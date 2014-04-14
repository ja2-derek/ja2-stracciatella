
#if !defined(_MSC_VER)
  #include <strings.h>
#endif
#include "Smack_Stub.h"
#include "Sound_Control.h"
#include "SoundMan.h"
extern "C" {
#include "smacker/smacker.h"
}

BOOLEAN SmackCheckStatus(CHAR8 smkstatus) {
  if (smkstatus <0) {
    printf ("SmackLibrary returned an error!\n");
    return TRUE;
  }
  return FALSE;
}

// read all smackaudio and convert it to 22050Hz on the fly (44100 originally)
UINT32 SmackGetAudio (const smk SmkObj, const ULONG32 Frames, const CHAR8* audiobuffer) 
{
  UINT32 audiolen = 0,  smacklen = 0;
  UINT16 i, index;
  INT16 *smackaudio, *paudio = (INT16*) audiobuffer;
  const CHAR8 track = 0; // only track0
  CHAR8 status = 0;

  if (! audiobuffer ) return 0;
 
  // disable video - enable audio
  status = smk_enable_video(SmkObj, DISABLE);
  SmackCheckStatus(status);
  status = smk_enable_audio(SmkObj, track, ENABLE);
  SmackCheckStatus(status);
  smk_first (SmkObj);
  do {
    smackaudio = (INT16*) smk_get_audio (SmkObj, track);
    smacklen = smk_get_audio_size (SmkObj, track);
    index = 0; i = smacklen/8;
    while  ( i > 0 )
      {
        *paudio++ = ((smackaudio[ index   ] +smackaudio[index+2])>>1);
        *paudio++ = ((smackaudio[ index +1] +smackaudio[index+3])>>1);
        index += 4;
        i--;
      } 
    audiolen += smacklen/4;
    //printf ("Restlen i: %u from smacklen/4: %u\n", (smacklen/4-smacklen%4)-i, smacklen/4-smacklen%4);
  } while (  smk_next(SmkObj) != SMK_DONE  );

  smk_enable_audio (SmkObj,  track, DISABLE);
  return audiolen;
}


UINT32 SmackGetInfo ( Smack* object ) 
{
  //smk smackinfo = object->Smacker;
  /*  ULONG32 frame, framecount,  width, height;
  UCHAR8 scale;
  DOUBLE usf;
  CHAR8 smkstatus; */
  //union smk_read_t fp;
  /* arrays for audio track metadata */
  /*
  UCHAR8  a_trackmask, a_channels[7], a_depth[7];
  ULONG32   a_rate[7];

  smackinfo = object->Smacker;

  smkstatus = smk_info_video (smackinfo->Smacker, &width, &height, &scale);
  smkstatus = smk_info_all   (smackinfo->Smacker, &frame, &framecount, &usf);

  smkstatus = smk_info_audio(smackinfo->Smacker,  &a_trackmask, a_channels, a_depth, a_rate);

  
  smackinfo->smkaudiotrack.freq=a_rate[track];
  smackinfo->smkaudiotrack.channels=a_channels[track];
  smackinfo->smkaudiotrack.format=AUDIO_S16;
  smackinfo->smkaudiotrack.samples = 1024; 
  smackinfo->smkaudiotrack.userdata = NULL;
  smackinfo->Frames=framecount;
  smackinfo->FrameNum=frame;
  smackinfo->Height=height;
  smackinfo->FramesPerSecond = usf;
  */
  return 0;
}

Smack* SmackOpen(const CHAR8* FileHandle, UINT32 Flags, UINT32 ExtraBuf)
{
  Smack* flickinfo;
  // smacklib info types
  ULONG32 frame, framecount,  width, height;
  UCHAR8 scale;
  DOUBLE usf;
  CHAR8 smkstatus;
  union smk_read_t fp;
  /* arrays for audio track metadata */
  UCHAR8    a_depth[7], a_channels[7];
  ULONG32   a_rate[7];
  const CHAR8 track = 0;
  CHAR8* audiobuffer;
  ULONG32 audiolen, audiosamples;

  fp.file = (FILE*)FileHandle;
  flickinfo = (Smack*)malloc (sizeof (Smack)); 

  // open file with given filehandle
  flickinfo->Smacker = smk_open_generic(1, fp, 0, SMK_MODE_DISK);
  //flickinfo->Smacker = smk_open_generic(1, fp, 0, SMK_MODE_MEMORY);
  if ( ! flickinfo->Smacker ) return NULL;

  SmackGetInfo (flickinfo);

  smkstatus = smk_info_video (flickinfo->Smacker, &width, &height, &scale);
  SmackCheckStatus(smkstatus);
  smkstatus = smk_info_all   (flickinfo->Smacker, &frame, &framecount, &usf);
  SmackCheckStatus(smkstatus);
  smkstatus = smk_info_audio(flickinfo->Smacker,  NULL, a_channels, a_depth, a_rate);
  SmackCheckStatus(smkstatus);

  flickinfo->Frames=framecount;
  flickinfo->FrameNum=frame;
  flickinfo->Height=height;
  flickinfo->FramesPerSecond = usf;
  // calculate needed memory
  audiosamples = ( (flickinfo->Frames / (usf/1000) * (a_rate[track]/2) * 16 *  a_channels[track]));
  //printf ("Malloc Audio: %luMb FPS: %f channels: %d depth: %d\n", audiosamples/1024/1024, usf/1000, a_channels[track], a_depth[track] );
  audiobuffer = (CHAR8*) malloc( audiosamples );
  //if ( (smk_first(flickinfo->Smacker) < 0)) { printf ("First Failed!"); return NULL; }
  if ( ! audiobuffer ) return NULL;
  flickinfo->audiobuffer = audiobuffer;
  audiolen = SmackGetAudio (flickinfo->Smacker, framecount, audiobuffer);
  if ( audiolen > 0 ) SoundPlayFromBuffer( audiobuffer, audiolen, MAXVOLUME, 64, 1, NULL, NULL);
  smk_enable_video (flickinfo->Smacker, ENABLE);
  if ( (smk_first(flickinfo->Smacker) < 0)) { printf ("First Failed!"); return NULL; }
  smk_first(flickinfo->Smacker);
  flickinfo->LastTick = SDL_GetTicks();
  return flickinfo;
}


UINT32 SmackDoFrame(Smack* Smk)
{
  // wait for FPS milliseconds
  UINT32 millisecondspassed = SDL_GetTicks() - Smk->LastTick;
  UINT32 delay = 0;
  if (  Smk->FramesPerSecond/1000 > millisecondspassed ) {
    delay = Smk->FramesPerSecond/1000-millisecondspassed;
    //printf ("Ticks %u  Delay: %u ", millisecondspassed, delay);
  }
  SDL_Delay(delay);
  Smk->LastTick = SDL_GetTicks();
  return 0;
}


CHAR8 SmackNextFrame(Smack* Smk)
{
  ULONG32 cur_frame; 
  CHAR8 smkstatus;
  smkstatus = smk_next(Smk->Smacker);
  smk_info_all(Smk->Smacker, &cur_frame, NULL, NULL);
  //printf ("Frame: %d cur_frame: %lu\n", Smk->FrameNum, cur_frame);
  Smk->FrameNum = cur_frame;
  return smkstatus;
}


UINT32 SmackWait(Smack* Smk)
{

  return 0;
}


void SmackClose(Smack* Smk)
{
  smk_close (Smk->Smacker);
}

// stolen from driver.c (which was part of libsmacker-1.0)
void dump_bmp(unsigned char *pal, unsigned char *image_data, unsigned int w, unsigned int h, unsigned int framenum)
{
        int             i;
        FILE           *fp;
        char            filename  [128];
        unsigned int    temp;
        sprintf(filename, "/tmp/out_%04u.bmp", framenum);
        fp = fopen(filename, "wb");
        fwrite("BM", 2, 1, fp);
        temp = 1078 + (w * h);
        fwrite(&temp, 4, 1, fp);
        temp = 0;
        fwrite(&temp, 4, 1, fp);
        temp = 1078;
        fwrite(&temp, 4, 1, fp);
        temp = 40;
        fwrite(&temp, 4, 1, fp);
        fwrite(&w, 4, 1, fp);
        fwrite(&h, 4, 1, fp);
        temp = 1;
        fwrite(&temp, 2, 1, fp);
        temp = 8;
        fwrite(&temp, 4, 1, fp);
        temp = 0;
        fwrite(&temp, 2, 1, fp);
        temp = w * h;
        fwrite(&temp, 4, 1, fp);
        temp = 0;
        fwrite(&temp, 4, 1, fp);
        fwrite(&temp, 4, 1, fp);
        temp = 256;
        fwrite(&temp, 4, 1, fp);
        temp = 256;
        fwrite(&temp, 4, 1, fp);
        temp = 0;
        for (i = 0; i < 256; i++)
        {
                fwrite(&pal[(i * 3) + 2], 1, 1, fp);
                fwrite(&pal[(i * 3) + 1], 1, 1, fp);
                fwrite(&pal[(i * 3)], 1, 1, fp);
                fwrite(&temp, 1, 1, fp);
        }

        for (i = h - 1; i >= 0; i--)
        {
                fwrite(&image_data[i * w], w, 1, fp);
        }

        fclose(fp);
}

void SmackToBuffer(Smack* Smk, UINT32 Left, UINT32 Top, UINT32 Pitch, UINT32 DestHeight, void* Buf, UINT32 Flags)
{
  unsigned char* smackframe, *pframe;
  unsigned char* smackpal;
  UINT16 i,j,pixel,*buf;
  UINT8 *rgb;
  UINT32 halfpitch = Pitch / 2;
  smackframe = smk_get_video(Smk->Smacker);
  smackpal = smk_get_palette (Smk->Smacker);
  // dump_bmp (smackpal, smackframe, 640, 480, Smk->FrameNum);
  buf=(UINT16*)Buf;
  pframe=smackframe;
  // for now hardcoded without taking sdl into account. 
  // need to find a way to blit it later
  if (Flags == SMACKBUFFER565) 
    {
      buf+=Left + Top*halfpitch;
      for (i =0; i < DestHeight ; i++) {
        for (j = 0; j <640; j++) {
          // get rgb offset of palette
          rgb = &smackpal[*pframe++*3] ;
          // convert from rbg to rgb565 0=red 1=green 2=blue
          *buf++ = (rgb[0]>>3)<<11 | (rgb[1]>>2)<<5 | rgb[2]>>3;
        }
        buf+=halfpitch-640;
      }
    }
  else 
    {
      for (i =0; i < DestHeight ; i++) {
        for (j = 0; j <640; j++) {
          // get rgb offset of palette
          rgb = &smackpal[pframe[0]*3] ;
          // convert from rbg to rgb555 0=red 1=green 2=blue
          //pixel = (rgb[0]>>3)<<10 | (rgb[1]>>2)<<5 | rgb[2]>>3;
          buf[(j+Top)+(i+Left)*halfpitch]=pixel;
          pframe++;
        }
      }
    }
}

// not needed
/*
SDL_Surface* SmackBufferOpen(UINT32 BlitType, UINT32 Width, UINT32 Height, UINT32 ZoomW, UINT32 ZoomH)
{
  SDL_Surface* buffer;
  buffer = SDL_CreateRGBSurface(BlitType, Width, Height, 16, 0, 0, 0, 0);
  if ( ! buffer ) {
    fprintf(stderr, "CreateRGBSurface failed: %s       ", SDL_GetError());
    exit (1);
  }
  return buffer;
}
*/

/*
void SmackBufferClose(SmackBuf* SBuf)
{
  free (SBuf);
}
*/


UINT32 SmackUseMMX(UINT32 Flag)
{
	return 0;
}
