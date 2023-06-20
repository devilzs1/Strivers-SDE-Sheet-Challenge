#include<bits/stdc++.h>
string reverseString(string &str){
	// Write your code here.
	string revStr = "",temp="";
	stack<string> st;
	int n = str.length();
	for(int i=0;i<n;i++){
		if(str[i]!=' '){
			temp+=str[i];
		}else{
			if(temp.length()){
				st.push(temp);
				temp = "";
			}
		}
	}
	if(temp.length()){
		st.push(temp);
	}
	while(!st.empty()){
		if(revStr.length()) revStr+= " " + st.top();
		else revStr +=st.top();

		st.pop();
	}
	return revStr;
}
// string reverseString(string &str){
// 	// Write your code here.
// 	string revStr = "",temp="";
// 	int n = str.length();
// 	for(int i=0;i<n;i++){

// 		if(str[i]!=' '){
// 			temp+=str[i];
// 		}else{
// 			if(temp.length()){
// 				if(revStr.length()) revStr = temp + " " + revStr;
// 				else revStr = temp;
// 				temp = "";
// 			}
// 		}
// 	}
// 	if(temp.length()){
// 		if(revStr.length()) revStr = temp + " " + revStr;
// 		else revStr = temp;
// 	}

// 	return revStr;
// }