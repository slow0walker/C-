#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
// 将12小时制时间转换为从午夜开始的分钟数
int timeToMinutes(int hour, int minute, char period[])
{
	if (toupper(period[0]) == 'P' && hour != 12)
	{
		hour += 12;
	}
	else if (toupper(period[0]) == 'A' && hour == 12)
	{
		hour = 0;
	}
	return hour * 60 + minute;
}

int main()
{
	// 航班起飞时间（12小时制）和抵达时间（12小时制），转换为分钟数存储
	typedef struct Flight {
	const char dep_time[15];
	const char arr_time[15];
		int dep_mins;
	}Flight;

	Flight flights[] = {
		{"8:00 a.m.", "10:16 a.m.", 480},
		{"9:43 a.m.", "11:52 a.m.", 583},
		{"11:19 a.m.", "1:31 p.m.", 679},
		{"12:47 p.m.", "3:00 p.m.", 767},
		{"2:00 p.m.", "4:08 p.m.", 840},
		{"3:45 p.m.", "5:55 p.m.", 945},
		{"7:00 p.m.", "9:20 p.m.", 1140},
		{"9:45 p.m.", "11:58 p.m.", 1305}
	};

	int num_flights = sizeof(flights) / sizeof(flights[0]);

	int hour, minute;
	char period[5]="", ch;
	printf("Enter a 12-hour time: ");
	scanf("%d:%d", &hour, &minute);

	while ((ch = getchar()) != '\n') {
		if (isalpha(ch)) {
			strncat(period, &ch, 1);
		}
	}

	period[0] = toupper(period[0]); // 统一转为大写方便判断

	int input_mins = timeToMinutes(hour, minute, period);

	int min_diff = 1440, close_id = 0;
	for (int i = 0; i < num_flights; ++i)
	{
		int diff = abs(input_mins - flights[i].dep_mins);
			if (diff < min_diff)
			{	
				min_diff = diff;
				close_id = i;
			}
	}
	printf("Closest departure time is %s, arriving at %s.\n",
		flights[close_id].dep_time, flights[close_id].arr_time);

	return 0;
}