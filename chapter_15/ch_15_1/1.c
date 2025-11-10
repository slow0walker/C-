#define _CRT_SECURE_NO_WARNINGS 1
void write_line(void)
{
    int extra_spaces, spaces_to_insert, i, j;
    int spaces_between = num_words - 1;
    int alternate = 0;  // 0 表示从左边开始分配余数，1 表示从右边开始
    extra_spaces = MAX_LINE_LEN - line_len;

    for (i = 0; i < line_len; i++)
    {
        if (line[i] != ' ')
        {
            putchar(line[i]);
        }
        else
        {
            // 基本分配
            spaces_to_insert = extra_spaces / spaces_between;

            // 若还有余数，交替分配一个空格
            if (extra_spaces % spaces_between != 0)
            {
                if (alternate == 0)
                {
                    spaces_to_insert++;
                    alternate = 1;
                }
                else
                {
                    alternate = 0;
                }
            }

            // 实际打印空格
            for (j = 0; j <= spaces_to_insert; j++)
                putchar(' ');

            // 更新剩余空格与剩余间隙数
            extra_spaces -= spaces_to_insert;
            spaces_between--;
        }
    }
    putchar('\n');
}
