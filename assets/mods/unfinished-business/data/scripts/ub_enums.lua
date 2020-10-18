
UB_EventTypes = {
    EVENT_ATTACK_INITIAL_SECTOR_IF_PLAYER_STILL_THERE = 81,
    EVENT_SAY_DELAYED_MERC_QUOTE = 82,

    EVENT_DELAY_SOMEONE_IN_SECTOR_MSGBOX = 83,
    EVENT_SECTOR_H8_DONT_WAIT_IN_SECTOR = 84,
    EVENT_SEND_ENRICO_UNDERSTANDING_EMAIL = 85,
}

UB_MercProfiles = {
    GASTON = 58,
    STOGIE = 59,
    MANUEL = 60,
    BIGGENS = 61,
    JOHN_K = 62,
    TEX = 64,

    BETTY = 73,
    RAUL = 74,
    MORRIS = 75,
    JERRY = 76,
    RUDY = 77,
}

UB_JerryQuotes = {
    MILO_QUOTE__OPENING_GREETING_PART_1 = 0,
    MILO_QUOTE__OPENING_GREETING_PART_2 = 1,
    MILO_QUOTE__FRIENDLY_APPROACH_NOTHING_TO_SAY = 2,
    MILO_QUOTE__FRIENDLY_APPROACH_NOTHING_TO_SAY_ALT = 3,
    MILO_QUOTE__REFUSE_TO_ACCEPT_ITEM = 4,
    MILO_QUOTE__DIRECT_APPROACH_NOTHING_TO_SAY = 5,
    MILO_QUOTE__THREATEN_APPROACH_NOTHING_TO_SAY = 6,
    MILO_QUOTE__RECRUITMENT_REFUSAL = 7,
    MILO_QUOTE__WOUNDED = 8,
    MILO_QUOTE__GET_LOST = 9,
    MILO_QUOTE__ACCEPT_MONEY = 10,
    MILO_QUOTE__PLAYER_HAS_MORE_THEN_6_MERCS = 11,
    MILO_QUOTE__PLAYER_HAS_MORE_THEN_6_MERCS_2ND_TIME = 12,
    MILO_QUOTE__PLAYER_HAS_LESS_THEN_6_MERCS = 13,
    MILO_QUOTE__CRASH_QUOTE = 14,
    MILO_QUOTE__FOLLOWS_PC_ANSWER_TO_14_PART_1 = 15,
    MILO_QUOTE__FOLLOWS_PC_ANSWER_TO_14_PART_2 = 16,
    MILO_QUOTE__FOLLOWS_PC_ANSWER_TO_14_PART_3 = 17,
    MILO_QUOTE__ALTERNATE_DIRECT_DEFAULT = 18,
    MILO_QUOTE__FIRST_RESPONSE_TO_THREATENING = 19,
    MILO_QUOTE__DEFAULT_COWERING_QUOTE = 20,
    MILO_QUOTE__HEADED_TO_TRACONA_QUOTE = 21,
    MILO_QUOTE__JERRY_HEALED = 22,
    MILO_QUOTE__JERRY_BECOMES_ENEMY = 23,
    MILO_QUOTE__ALREADY_HAS_6_MERCS = 24,
    MILO_QUOTE__PLAYER_HAS_NO_MERCS = 25,
}

UB_Weapons = {
    NONE = 0,
    BARRETT = 43,
    CALICO_960 = 44,
    PSG1 = 45,
    L85 = 46,
    TAR21 = 47,
    VAL_SILENT = 48,
    MICRO_UZI = 57,
    HAND_CANNON = 63,   --The antique musket cannon Raul is looking for
    CALICO_950 = 66,
    CALICO_900 = 67,
    HARTFORD_6_SHOOTER = 68,  --Tex's guns
    SAM_GARVER_COMBAT_KNIFE = 69,
    MERC_UMBRELLA = 70,
}

UB_Quests = {
    QUEST_DESTROY_MISSLES = 23,
    QUEST_FIX_LAPTOP = 24,
    QUEST_GET_RID_BLOODCATS_AT_BETTYS = 25,
    QUEST_FIND_ANTIQUE_MUSKET_FOR_RAUL = 26,
}

UB_Facts = {
    FACT_IMPORTED_SAVE_AND_MARY_WAS_DEAD = 400,
    FACT_JOHN_KULBA_OFFERED_TO_BE_RECRUITED = 401,
    FACT_TEX_IS_IN_GAME_AND_ALIVE_IN_STORE = 402,
    FACT_PLAYER_PAID_BETTY_MORE_THEN_X_FOR_ITEM =403,
    FACT_PLAYER_BOUGHT_A_TEX_VIDEO_FROM_BETTY = 404,
    FACT_RAULS_INVENTORY_CHANGED_SINCE_LAST_VISIT = 405,
    FACT_PLAYER_THREATENED_RAUL_COUPLE_TIMES = 406,
    FACT_PLAYER_BOUGHT_SOMETHING_FROM_RAUL = 407,
    FACT_PLAYER_BOUGHT_BARRET_FROM_RAUL = 412,
    FACT_MERC_SAY_QUOTE_WHEN_TALK_MENU_CLOSES = 413,
    FACT_PLAYER_IMPORTED_SAVE_MIGUEL_DEAD = 414,
    FACT_PLAYER_IMPORTED_SAVE_FATIMA_OR_PACOS_DEAD = 415,
    FACT_PLAYER_IMPORTED_SAVE_CARLOS_DEAD = 416,
    FACT_PLAYER_IMPORTED_SAVE_IRA_DEAD = 417,
    FACT_PLAYER_IMPORTED_SAVE_DIMITRI_DEAD = 418,
    FACT_PLAYER_IMPORTED_SAVE = 419,
    FACT_PLAYER_KILLED_ALL_BETTYS_BLOODCATS = 420,
    FACT_BIGGENS_IS_ON_TEAM = 421,
    FACT_FAN_STOPPPED = 422,
    FACT_BIGGENS_ON_TEAM_AND_FAN_STOPPED = 423,
    FACT_PLAYER_KNOWS_ABOUT_FAN_STOPPING = 424,
}

UB_Quotes = {
    QUOTE_LAPTOP_FIXED = 79,
    QUOTE_STILL_ALIVE = 80,
    QUOTE_COMPLAIN_BAD_PILOT = 81,
    QUOTE_DONT_STAY_FOR_LONG = 82,
    QUOTE_COMPLAIN_ITS_COLD = 85,
    QUOTE_MANUEL_JOINED = 96,
    QUOTE_BIGGENS_JOINED = 97,
    QUOTE_JOHNK_JOINED = 98,
    QUOTE_TEX_JOINED = 99,

    QUOTE_HAND_CANNON_COMMENT = 106 , --was: QUOTE_PRECEDENT_TO_REPEATING_ONESELF_RENEW
    QUOTE_NEW_GUN_COMMENT = 100 , --was: QUOTE_HATE_MERC_1_ON_TEAM_WONT_RENEW
}

UB_NPCActions = {
    NPC_ACTION_TRIGGER_JERRY_CONVERSATION_WITH_PGC_1 = 301,
    NPC_ACTION_TRIGGER_JERRY_CONVERSATION_WITH_PGC_2 = 302,

    NPC_ACTION_LEAVING_NPC_TALK_MENU = 304,
    NPC_ACTION_BIGGENS_DETONATES_BOMBS = 305,

    NPC_ACTION_RAUL_BLOWS_HIMSELF_UP = 306,
    NPC_ACTION_TEX_FLUSHES_TOILET = 307,
    NPC_ACTION_MARK_TEX_AS_ALREADY_INTRODUCED_HIMSELF = 308,
    NPC_ACTION_MAKE_TEX_CAMOED = 309,
    NPC_ACTION_HAVE_DEALER_OPEN_BUY_SELL_SCREEN = 310,
}


UB_Emails = {
    -- email # 1
    STARTGAME = 0,
    STARTGAME_LENGTH = 8,
    -- email # 2
    PILOTMISSING = 8,
    PILOTMISSING_LENGTH = 2,
    -- email # 3
    MAKECONTACT = 10,
    MAKECONTACT_LENGTH = 3,
    -- email # 4
    MANUEL = 13,
    MANUEL_LENGTH = 4,
    -- email # 5  - only if Miguel is alive!
    MIGUELHELLO = 17,
    MIGUELHELLO_LENGTH = 3,
    -- email # 6 - player not advancing fast enough
    CONCERNED = 20,
    CONCERNED_LENGTH = 2,
    -- email # 7 - player still not advancing fast enough
    URGENT = 22,
    URGENT_LENGTH = 3,
    -- email # 8a  - from Miguel
    MIGUELSORRY = 25,
    MIGUELSORRY_LENGTH = 3,
    -- email # 8b  - from Miguel, mentioning Manuel
    MIGUELMANUEL = 28,
    MIGUELMANUEL_LENGTH = 4,
    -- email # 9 - Miguel sick
    MIGUELSICK = 32,
    MIGUELSICK_LENGTH = 3,
    -- email # 10a
    UNDERSTANDING = 35,
    UNDERSTANDING_LENGTH = 3,
    -- email # 10b - if we need extra cash
    EXTRACASH = 38,
    EXTRACASH_LENGTH = 4,
    -- email # 11
    PILOTFOUND = 42,
    PILOTFOUND_LENGTH = 2,
    -- email # 12a - Miguel dead, Manuel never recruited
    CONGRATS = 44,
    CONGRATS_LENGTH = 4,
    -- email # 12b - Miguel alive, Manuel never recruited
    CONGRATSICK = 48,
    CONGRATSICK_LENGTH = 5,
    -- email # 12c - Miguel alive, Manuel dead
    CONGRATMIGMANUELDEAD = 53,
    CONGRATMIGMANUELDEAD_LENGTH = 6,
    -- email # 12d - Miguel alive, Manuel recruited and alive
    CONGRATMIGMANUELALIVE = 59,
    CONGRATMIGMANUELALIVE_LENGTH = 6,
    -- email # 12e - Miguel dead, Manuel dead
    CONGRATMANUELDEAD = 65,
    CONGRATMANUELDEAD_LENGTH = 5,
    -- email # 12f -  Miguel dead, Manuel recruited and alive
    CONGRATMANUELALIVE = 70,
    CONGRATMANUELALIVE_LENGTH = 5,
    -- email # 13 - original AIM email
    AIMDISCOUNT = 75,
    AIMDISCOUNT_LENGTH = 7,
    --
    MANUEL_AT_HOME_NOT_USED = 82,
    MANUEL_AT_HOME_NOT_USED_LENGTH = 1,
    -- Email #14 Initial IMP email
    IMP_EMAIL_INTRO = 83,
    IMP_EMAIL_INTRO_LENGTH = 10,
    -- Email #15 Imp follow up
    IMP_EMAIL_AGAIN = 93,
    IMP_EMAIL_AGAIN_LENGTH = 5,
    -- email #16 - ??  merc left-me-a-message-and-now-I'm-back emails
    AIM_REPLY_BARRY = 98,
    AIM_REPLY_LENGTH_BARRY = 2,
    AIM_REPLY_MELTDOWN = 176, -- 98 + (39 * 2)
    AIM_REPLY_LENGTH_MELTDOWN = 2,
    --
    AIM_REFUND = 178,
    AIM_REFUND_LENGTH = 3,
    MERC_REFUND = 181,
    MERC_REFUND_LENGTH = 3,
    --
    AIM_PROMOTION_1 = 184,
    AIM_PROMOTION_1_LENGTH = 4,
    MERC_PROMOTION_1 = 188,
    MERC_PROMOTION_1_LENGTH = 5,
    AIM_PROMOTION_2 = 193,
    AIM_PROMOTION_2_LENGTH = 5,
    --
    IMP_PROFILE_RESULTS = 198,
    IMP_PROFILE_RESULTS_LENGTH = 1
}

UB_EmailSenders = {
    MAIL_ENRICO=0,
    CHAR_PROFILE_SITE = 1,
    GAME_HELP = 2,
    IMP_PROFILE_RESULTS = 3,
    SPECK_FROM_MERC = 4,
    RIS_EMAIL = 5,
    FIRST_AIM_MERC = 6,
    LAST_AIM_MERC = 45,
    INSURANCE_COMPANY = 46,
    BOBBY_R = 47,
    KING_PIN = 48,
    JOHN_KULBA = 49,
    AIM_SITE = 50,
    MAIL_MIGUEL = 51,
}

INIT_SECTOR = "H7"
INIT_SECTOR_X = 7
INIT_SECTOR_Y = 8
