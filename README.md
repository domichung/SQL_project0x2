# SQL_project0x2

資料夾說明

> 6_19back為舊版檔案 可以忽略

> all_index 為 index 儲存區
    |
    |-> cut_index 做 index 裁切的檔案
    |
    |-> long 原始 index 長檔
    |
    |-> index_???? 切割後檔案放置位置

> create_index 以三種資料去做 index 以 tree 去建構她

> data_big5 題目原始檔案

> search_system 主要搜尋程式

> ???_index_to_data 搜尋涵式 會丟回 search_system

> cut.cpp 進行字串切割的自訂義涵式

申明 : 本人無使用任何資料庫中現成的樹 來進行建構

注意事項 : 檔案為big5編碼 若要使用中文索引請注意編碼問題