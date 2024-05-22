#include <iostream>
#include <fstream>
#include <cstring>
#include <cctype> // for using toupper
using namespace std;
void chapters(int &choice,string &file,string &reviewer,int &chapter){
    if(choice == 1){
        cout << "Chapter 1 - Fundamentals of C++\n";
        file = "chapter1.txt";
        reviewer = "reviewer1.txt";
    }else if(choice == 2){
        cout << "Chapter 2 - Looping and Array\n";
        file = "chapter2.txt";
        reviewer = "reviewer2.txt";
    }else if(choice == 3){
        cout << "Chapter 3 - References and Pointers\n";
        file = "chapter3.txt";
        reviewer = "reviewer3.txt";
    }
    chapter = choice;
    do{
        cout << "1. Review\n";
        cout << "2. Take Quiz\n";
        cout << "Input: ";
        cin >> choice;
        if(choice == 1){
            break;
        }else if(choice == 2){
            break;
        }
    }while(true);
}
void printChapter(int &choice){
   cout << "WELCOME TO EXAMINATION!" <<endl;
        cout << "Choose what Chapter | to exit input -1" << endl;
        cout << "1. Chapter 1 - Fundamentals of C++\n";
        cout << "2. Chapter 2 - Looping and Array\n";
        cout << "3. Chapter 3 - References and Pointers\n";
        cout << "4. Display Scores\n";
        cout << "Input: ";
        cin >> choice;
}
int main(){
	string username,password;
    string questions;
    string key_answer[3] = {"ABCABBBCAB","AABCA","ABBAA"};
	char your_answer[10];
	char upper;
	int choice, chapter;
    int chapter_scores[3] = {0,0,0};
    string file,reviewer;
	cout << "Examination Program" << endl;
	do{
		cout << "Username: ";
		cin >> username;
		cout << "Password: ";
		cin >> password;
		if(username == "admin" && password == "admin"){
			cout << "Logged In!" << endl;
			break;
		}else{
			cout << "Failed! Please Try Again." << endl;
		}
	}while(true);
	do{
        printChapter(choice);
        if(choice <= 4 && choice > 0){
            if(choice == 4){
                    cout << "\n---Score Per Chapter---\n";
                for(int i=0;i<sizeof(chapter_scores) / sizeof(int);i++){
                    cout << "Chapter " << i+1 << ": " << chapter_scores[i] <<endl;
                }
                cout << endl;
                system("pause");
                system("CLS");
            }else{
                chapters(choice,file,reviewer,chapter);
            }
            if(choice == 1){
                ifstream MyReadFile(reviewer);
                int i = 0;
                cout << "\n--------------------------------------\n";
                 while(getline(MyReadFile, questions)){
                    cout << questions << endl;
                }
                cout << "\n--------------------------------------\n";
                cout << "2. Take Quiz\n";
                cout << "Input: ";
                cin >> choice;
                system("CLS");
            }
            if(choice == 2){
                ifstream MyReadFile(file);
                int score = 0;
                int index = 0;
                while(getline(MyReadFile, questions)){
                    cout << questions << endl;
                    if(questions == "*"){
                        cout << "Your answer: ";
                        cin >> your_answer[index];
                        index++;
                    }
                }
                for(int i=0;i<key_answer[chapter-1].length();i++){
                    upper = toupper(your_answer[i]);
                    cout << upper << ',';
                    if(key_answer[chapter-1][i] == upper){
                        score += 1;
                    }
                }
                chapter_scores[chapter-1] = score;
                cout << "\nScore: " << chapter_scores[chapter-1] << endl;
                cout << "\n\n";
                system("pause");
                system("CLS");
            }
        }else if(choice == -1){
            break;
        }
	}while(true);

	return 0;
}
