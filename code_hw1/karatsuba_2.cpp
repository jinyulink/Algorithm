#include<bits/stdc++.h>
using namespace std;

string appendZero(string str, int n);
string karatsuba(string x, string y);
string multiplyXY(string x, string y);
string addXY(string x, string y);
string subtractXY(string x, string y);
string removeZero(string str);
string multiply10(string str, int n);

int main(){
	freopen("number.txt", "r" , stdin);
	string x,y;
	cin>>x;
	y=x;
	if(x == "0" || y == "0"){
		cout << "0" << endl;
	}else{
		if(x.length() > y.length()){
			y = appendZero(y, x.length() - y.length());
		}else{
			x = appendZero(x, y.length() - x.length());
		}
		string cout<<removeZero(karatsuba(x,y));
	}
	// cout << "karatsuba: " <<(double)clock() / CLOCKS_PER_SEC << " sec.\n";
	return 0;
}

string karatsuba(string x, string y){
	if(x.length() == 1 && y.length() == 1){
		return multiplyXY(x, y);
	}

	if(x.length() > y.length()){
		y = appendZero(y, x.length() - y.length());
	}else{
		x = appendZero(x, y.length() - x.length());
	}
	if(x.length()%2 !=0){
		x = "0" + x;
		y = "0" + y;
	}

	string x_left, x_right, y_left, y_right, p1, p2, p3;
	int n = x.length();

	x_left = x.substr(0, x.length()/2);
	x_right = x.substr(x.length()/2);
	y_left = y.substr(0, y.length()/2);
	y_right = y.substr(y.length()/2);
 	
	p1 = karatsuba(x_left, y_left);
	p2 = karatsuba(addXY(x_left, x_right), addXY(y_left, y_right));
	p3 = karatsuba(x_right, y_right);

	return addXY(addXY(multiply10(p1, n), multiply10(subtractXY(subtractXY(p2,p1), p3), n/2)), p3); 
}

string appendZero(string str, int n){
	while(n>0){
		str = "0" + str;
		n--;
	}
	return str;
}
string multiplyXY(string x, string y){
	int product;
	product = ((int)x[0] - '0') * ((int)y[0] - '0');
	return to_string(product);
}

string addXY(string x, string y){
	if(x.length() > y.length()){
		y = appendZero(y, x.length() - y.length());
	}else{
		x = appendZero(x, y.length() - x.length());
	}
	int carry = 0, sum;
	string result = "";
	for(int i = x.length() - 1; i >= 0; i--){
		sum = ((int)x[i] - '0') + ((int)y[i] - '0') + carry;

		if(sum > 9){
			result = to_string(sum%10) + result;
			carry = sum/10;
		}else{
			result = to_string(sum) + result;
			carry = 0;
		}
	}
	if(carry != 0){
		result = to_string(carry) + result;
	}
	return result;
}

string subtractXY(string x, string y){
	if(x.length() > y.length()){
		y = appendZero(y, x.length() - y.length());
	}else{
		x = appendZero(x, y.length() - x.length());
	}

	string result = "";
	int borrow = 0, a, b;
	for(int i = x.length() - 1; i>=0; i--){
		a = (int)x[i] - '0';
		b = (int)y[i] - '0';
		if(borrow == 1){
			a = a - 1;
		}
		if(a >= b){
			result = to_string(a - b) + result;
			borrow = 0;
		}else{
			a = a + 10;
			result = to_string(a - b) + result;
			borrow = 1;
		}
	}
	return removeZero(result);
}

string removeZero(string str){
	reverse(str.begin(), str.end());
	for(int i = str.length() - 1; i >= 0; i--){
		if(str[i] == '0'){
			str.pop_back();
		}else{
			break;
		}
	}
	if(str.empty()){
		return "0";
	}else{
		reverse(str.begin(), str.end());
		return str;
	}	
}

string multiply10(string str, int n){
	while(n>0){
		str = str + "0";
		n--;
	}
	return str;
}