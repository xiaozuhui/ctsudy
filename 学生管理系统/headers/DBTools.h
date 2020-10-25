//
// Created by xuzh on 2020/10/26.
//

#ifndef DEMO1_DBTOOLS_H
#define DEMO1_DBTOOLS_H

const char * CREATE_TABLE_STUDENT =
        "CREATE TABLE STUDENTS("  \
        "ID INT PRIMARY KEY      NOT NULL," \
        "NAME           VARCHAR  NOT NULL," \
        "AGE            INT      NOT NULL," \
        "NUMBER         VARCHAR  NOT NULL);";

const char * DB_NAME = "students.db";

static int CreateTableCallBack(void *NotUsed, int argc, char **argv, char **azColName);
static int InsertTableCallBack(void *NotUsed, int argc, char **argv, char **azColName);
static int UpdateTableCallBack(void *data, int argc, char **argv, char **azColName);
static int DeleteTableCallBack(void *data, int argc, char **argv, char **azColName);
static int SelectTableCallBack(void *data, int argc, char **argv, char **azColName);

#endif //DEMO1_DBTOOLS_H
