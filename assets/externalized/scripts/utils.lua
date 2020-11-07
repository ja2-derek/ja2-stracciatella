function flatten_table(table, prefix, output)
    output = output or {}
    prefix = prefix or ''
    for k,v in ipairs(table) do
        if type(v) == 'table' then
            flatten_table(v, k .. ".", output)
        elseif type(v) == 'function' then
            
        else
            table.insert(k, v)
        end
    end
    return output
end