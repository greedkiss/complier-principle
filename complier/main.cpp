#include <iostream>
#include <fstream>
#include <string>
using namespace std;
string buf = "hello main while 199";
string ans;
string key[28] = {
    "main",
    "if"
    "else",
    "while",
    "do",
    "for",
    "return",
    "+",
    "-",
    "*",
    "/",
    "%",
    ">",
    ">=",
    "<",
    "<=",
    "==",
    "!=",
    "=",
    ";",
    "(",
    ")",
    "{",
    "}",
    "int",
    "float",
    "double",
    "char"
};
int value[] = {'1','2','3','4','5','6','7','10','11','12','13','14','15','16','17','18','19','20','21','22','23','24','25','26','27','28','29','30'};
//这是一个文件的读取操作
/*int main()
{
    char ch;
    ifstream OpenFile("./program.txt");
    if (OpenFile.fail())

    {

        cout<<"打开文件错误!"<<endl;

        return 0;

    }
    OpenFile.get(ch);

    cout<<ch;

    OpenFile.close();
    return 0;
}*/
//we can assume that the file are readed by stream
void read (){

}
int judgeSpace(int i){
    if(buf[i] == ';'){
        return -1;
    }
    else if(buf[i] == ' '){
        return 1;
    }
    else if(buf[i]== '\r' || buf[i+1] == '\n'){
        return 2;
    }
    else if(buf[i] == '    '){
        return 4;
    }
    return 0;
}

void digitJudge(string& num, int& i){
    while(buf[i] - '0' >= 0 && buf[i] - '0'<= 9){
        num += buf[i];
        i++;
    }
    int flag = judgeSpace(i);
    i = i + flag;
}
int idJudge(string & id , int & i){
    if(judgeSpace(i) == 0){
        while(judgeSpace(i) == 0){
            id += buf[i];
            i++;
        }
        i = i + judgeSpace(i);
        return 1;
    }
    return 0;
}
void keywordJudge(string& tem , int& i, int& j, string &num){
    int flag = 1;
    num  = '8';
    for(int k =0 ;k <key[j].size();k++, i++){
        if(buf[i] == key[j][k]){
            tem += buf[i];
        }else{
            flag = 0;
            i= i- k;
            break;
        }
    }
    if(flag && judgeSpace(i) != 0){
        num = value[j];
        i = i + judgeSpace(i);
    }else{
        idJudge(tem, i);
    }
}

int main(){
    int i = 0;
    //read();
    while(buf[i] != '\0'){
        //判断是否是数字
        int idx = buf[i] - '0';
        if(idx <= 9 && idx >= 0){
            string num;
            digitJudge(num , i);
            string term = "(" + num + "," + "9" + ")";
            ans += term;
        }
        //关键字，符号判断,标识符
        for(int j = 0;j< 28;j++){
            if(buf[i] == key[j][0]){
                string tem;
                string num;
                keywordJudge(tem, i, j, num);
                string term = "(" + tem + "," + num + ")";
                ans += term;
            }
        }
        //标识符
        string id;
        int flag = idJudge(id, i);
        if(flag){
            string term = "(" + id + "," + '9' +")";
            ans += term;
        }
    }
    cout<<ans;
    return 0;
}
