void Draw::Update(void)
{
    memset(_bitmap, 0xff, _w * _h * 3);
    SetForeColor(0);
    SetBackColor(~0);

    std::string s[] = {
        //
        "铁马云雕共绝尘", "柳营高压汉宫春", "天清杀气屯关右", "夜半妖星照渭滨", "下国卧龙空寤主", "中原得鹿不由人",
        "象床宝帐无言语", "从此谯周是老臣"
        };

    HZFONT* fonts[] = {&HZFONT_11X11, &HZFONT_12X12, &HZFONT_14X14, &HZFONT_16X16};

    for(int j = 0; j < 4; j++) {
        SetFont(fonts[j]);
        for(unsigned int i = 0; i < sizeof(s) / sizeof(s[0]); i++)
            HZ_PutString(s[i].c_str(), 100 + j * 120, 100 + i * (fonts[j]->char_height + 2));
    }

}
