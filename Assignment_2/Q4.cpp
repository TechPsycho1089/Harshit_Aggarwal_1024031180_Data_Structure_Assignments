#include <iostream>
#include <vector>
using namespace std;
int calculateLength(char arr[]){
    int i=0;
    while (arr[i]!='\0') i++;
    return i;
}
void lower(char arr[]){
    int i=0;
    while(arr[i]!='\0'){
        if (arr[i]>='A' && arr[i]<='Z')arr[i]=arr[i]+32;
        i++;
    }
}
void sortSentence(char sen[][100],int words){
    int k=0;char temp[100];int size;bool flag;
    for (int i=0;i<words;i++){
        flag = false;
        for (int j=0;j<words-i-1;j++){
            while (sen[j][k]==sen[j+1][k]&&sen[j][k]!='\0'&&sen[j+1][k]!='\0')k++;
            if (sen[j][k]>sen[j+1][k]){
                flag = true;
                for (int l=0;sen[j][l]!='\0'||sen[j+1][l]!='\0';l++){
                    temp[l]=sen[j][l];
                    sen[j][l] = sen[j+1][l];
                    sen[j+1][l]=temp[l];
                }
            }k=0;
        }
        if (!flag) {
                cout<<"sort completed.";return;
            }
    }
}
void concatenation(char str1[],char str2[]){
    int i=calculateLength(str1),j=0;
    while (str2[j]!='\0')str1[i++]=str2[j++];
    str1[i] = '\0';
}
void input(char str[]){
    cout<<"Enter the string. ";
    cin.getline(str,100);
}
void display(char str[]){
    cout<<str<<endl;
}
void reverse(char str[],char revStr[]){
    int i=calculateLength(str),j=0;
    while (j<i) revStr[j++]=str[i-j-1];
    revStr[j]='\0';
    str = revStr;
}
void removeVowels(char str[]){
    int i=calculateLength(str),z=0;
    for (int y=0;y<i;y++){
        str[z++]=str[y];
        if (str[y]=='a'||str[y]=='e'||str[y]=='i'||str[y]=='o'||str[y]=='u'||str[y]=='A'||str[y]=='E'||str[y]=='I'||str[y]=='O'||str[y]=='U') z--;
    }
    str[z]='\0';
}
int main(){
    char str1[100],str2[100];int size,i,j;
    input(str1);
    input(str2);
    display(str1);
    display(str2);
    cout<<"Concatenation\n";
    concatenation(str1,str2);
    cout<<str1<<endl;
    cout<<"Reverse\n";
    reverse(str1, str2);
    display(str2);
    cout<<"Remove vowels\n";
    removeVowels(str1);
    display(str1);

    // int n;
    // cout << "Enter number of words: ";
    // cin >> n;
    // cin.ignore();

    // char sen[50][100];
    // for (int i = 0; i < n; i++) {
    //     cout << "Enter word " << i + 1 << ": ";
    //     cin.getline(sen[i], 100);
    // }

    // sortSentence(sen, n);

    // cout << "\nSorted words:\n";
    // for (int i = 0; i < n; i++) {
    //     cout << sen[i] << endl;
    // }

    lower(str1);
    display(str1);

    return 0;
}