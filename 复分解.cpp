#include<bits/stdc++.h>
using namespace std;
string yang(string input) {
	int n=1;
	if((input[n] >= 65 && input[n] <= 90) || (input[n] >= 48 && input[n] <= 57)) {
		return string(1, input[0]); // 如果第二个字母是大写字母或数字，则第一个字母是阳离子
	}
	if(input[n] >= 97 && input[n] <= 122) {
		return input.substr(0,n+1);//如果第二个字母是小写字母，则第一第二个字母是阳离子
	}
}
int cut(string input) {
	int n=1;
	while(true) {
		if(input[n] >= 65 && input[n] <= 90) {
			return n;
			break;
		}
		n++;//分析阴离子是从哪里开始的
	}
}
string yin(string input,int line) {
	int n = line;
	while (n<input.length()) {
		if (input[n] >= 48 && input[n] <= 57) {
			return input.substr(line,input.length()-line-1);
			break;
		}
		n++;
	}
	return input.substr(line,input.length()-line);
}
bool judge(string yang_,string yin_) {

	string list[10]= {"HCO","HOH","CaCO","CuOH","FeOH","BaSO","AgCl","MgOH","AlOH","BaCO"};//有沉淀/水/气体生成即可
	bool re=false;
	for(int n=0; n<=9; n++) {//判断是否符合条件
		if((yang_+yin_)==list[n]) {
			re=true;
			break;
		}
	}
	return re;
}
int main() {
	string input1,input2;
	cin>>input1>>input2;
	string yang1=yang(input1);
	string yang2=yang(input2);
	int line1=cut(input1);
	int line2=cut(input2);
	string yin1=yin(input1,line1);
	string yin2=yin(input2,line2);
	if(judge(yang1,yin2) || judge(yang2,yin1)) {//判断，输出结果
		cout<<input1.substr(0,line1)<<input2.substr(line2,input2.length()-line2);
		cout<<"+";
		cout<<input2.substr(0,line2)<<input1.substr(line1,input1.length()-line1);
	} else {
		cout <<"NO";
	}
	return 0;
}
