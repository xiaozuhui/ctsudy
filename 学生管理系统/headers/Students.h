//
// Created by xuzh on 2020/10/26.
//

#ifndef DEMO1_STUDENTS_H
#define DEMO1_STUDENTS_H

typedef struct Students{
    char Name[10];
    int  Age;
    char Number[20];
    int  ID;
}Students;

/**
 * 添加学生
 * @param name 姓名
 * @param age 年龄
 * @param number 学号
 * @return
 */
int AddStudent(char * name, int age, char * number);
/**
 * 删除学生
 * @param number 学号
 * @return
 */
int DelStudent(const char * number);
/**
 * 同步到数据库
 * @param ids 需要同步的学生的id
 * @return
 */
int SyncStudent(const int * ids);

/**
 * 获取所有的学生
 * @return
 */
Students * GetStudents();

/**
 * 根据学号获取学生
 * @param number
 * @return
 */
Students * GetStudents(char * number);

#endif //DEMO1_STUDENTS_H
