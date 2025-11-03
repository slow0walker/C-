#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

#define STUDENTS 5
#define COURSES 5

int main()
{
	int scores[STUDENTS][COURSES] = { 0 };
	int student_total[STUDENTS] = { 0 };
	float student_avg[STUDENTS] = { 0.0f };
	float course_avg[COURSES] = { 0 };
	int course_high[COURSES] = { 0 };
	int course_low[COURSES] = { 0 };
	int i, j;

	for (i = 0; i < COURSES; i++)
	{
		printf("Enter scores for student %d (5 courses): ", i + 1);
		for (j = 0; j < STUDENTS; j++)
		{
			scanf("%d", &scores[i][j]);
			student_total[i] += scores[i][j];
			course_avg[j] += scores[i][j];
			// 初始化每门课的高低分
			if (i == 0 || scores[i][j] > course_high[j]) {
				course_high[j] = scores[i][j];
			}
			if (i == 0 || scores[i][j] < course_low[j]) {
				course_low[j] = scores[i][j];
			}
		}
		student_avg[i] = (float)student_total[i] / COURSES;
	}

	// 计算每门课的平均分
	for (j = 0; j < COURSES; j++) {
		course_avg[j] /= STUDENTS;
	}

	// 输出每个学生的总分和平均分
	printf("\nStudent totals and averages:\n");
	for (i = 0; i < STUDENTS; i++) {
		printf("Student %d: Total = %d, Average = %.2f\n",
			i + 1, student_total[i], student_avg[i]);
	}

	// 输出每门课的平均分、高分和低分
	printf("\nCourse statistics:\n");
	printf("Course\tAverage\tHigh\tLow\n");
	for (j = 0; j < COURSES; j++) {
		printf("%d\t%.2f\t%d\t%d\n",
			j + 1, course_avg[j], course_high[j], course_low[j]);
	}

	return 0;
}


