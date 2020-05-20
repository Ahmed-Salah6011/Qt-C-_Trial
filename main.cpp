#include<iostream>
#include <math.h>
#include <algorithm>
#include <string>
#include <bits/stdc++.h>
#include <fstream>
#include "Dict.h"
#include <QFile>
#include <QTextStream>
#include <QDir>
#include <QDebug>
#include <QCoreApplication>
using namespace std;


list<string> split(string line){
    int len = line.size();
    list <string> words;
    string word;
    for (int i = 0; i < len; i++)
    {
        if (ispunct(line[i]))
        {
            if (i == len - 1 && !word.empty()){
                words.push_back(word);
                continue;
            }
            line.erase(i--, 1);
            len = line.size();
        }
        else if (line[i] == ' ' && word.empty())
            continue;
        else if (line[i] == ' ' && !word.empty()){
            words.push_back(word);
            word.clear();
        }
        else
        {
            if ('A' <= line[i] && line[i] <= 'Z')
                line[i] = line[i] + 32;
            word = word + line[i];
            if (i == len - 1)
                words.push_back(word);
        }
    }
    return words;
}

template<typename S>
void remove_punc(S &str)
{
    for (int i =0,len=str.size();i<len;i++)
    {
        if (ispunct(str[i]) || str[i] ==' ')
        {
            str.erase(i--, 1);
            len = str.size();
        }
        else
        {
            if(str[i]>='A' && str[i]<='Z')
            {
                str[i]+=32;
            }
        }
    }
}


void display(string v)
{
    cout << v << " ";
}

int main(int argc,char* argv[])
{
    QCoreApplication a(argc ,argv);

    string x;
    Dict<QString, set<QString>> d;
    //"E:/questions/"
    //"E:/test_ds/"
    QString path = "E:/untitled/questions/";

    QDir mDir(path);
    QFileInfoList list=mDir.entryInfoList();

    for(int i=0;i<list.size();i++)
    {
        QFile file(list.at(i).absoluteFilePath());
        if(!file.open(QFile::ReadOnly|QFile::Text))
        {
            //qDebug()<<"failed to open";
            continue;
        }
        else
        {
            QTextStream in(&file);
            QString word;
            while(!in.atEnd())
            {
                in>>word;
                //string w = word.toUtf8().constData();
                //remove_punc(w);
                d.insert_set(word,list.at(i).absoluteFilePath());
            }
        }
    }
    set<QString> g=d.find("first");
    if(g.size()!=0)
    {
        for(auto it:g)
        {
            qDebug()<<it;
        }
    }


    return a.exec();
}
