#include <iostream>
#include <fstream>
#include <cstring>
#include <cctype> // for using toupper
using namespace std;
// THIS WILL PRINT SPECIFIC CHAPTER
void chapters(int &choice,string &file,string &reviewer,int &chapter,string &chapterFlavorText){
    if(choice == 1){
    	chapterFlavorText = "Chapter 1 - Fundamentals of C++\n";
        cout << "Chapter 1 - Fundamentals of C++\n";
        file = "chapter1.txt";
        reviewer = "reviewer1.txt";
    }else if(choice == 2){
    	chapterFlavorText = "Chapter 2 - Looping and Array\n";
        cout << "Chapter 2 - Looping and Array\n";
        file = "chapter2.txt";
        reviewer = "reviewer2.txt";
    }else if(choice == 3){
    	chapterFlavorText = "Chapter 3 - References and Pointers\n"; // TAKE CHAPTER FLAVOR TEXT
        cout << "Chapter 3 - References and Pointers\n"; // PRINT CHAPTER NAME
        file = "chapter3.txt"; // TAKE CHAPTER TXT NAME
        reviewer = "reviewer3.txt"; // TAKE REVIEWER TXT NAME
    }
    chapter = choice;
    do{
        cout << "1. Review\n";
        cout << "2. Take Quiz\n";
        cout << "3. Back\n";
        cout << "Input: ";
        cin >> choice;
        if(choice == 1 || choice == 2 || choice == 3){
            break;
        }
    }while(true);
}
// THIS WILL PRINT CHAPTERS
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
    string chapterFlavorText;
//	cout << "Examination Program" << endl;
	cout << "LOG IN" << endl;
//	LOGIN LOOP
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
//	MAIN MENU LOOP 
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
                chapters(choice,file,reviewer,chapter,chapterFlavorText);
            }
            // THIS WILL DO READ THE FILE REVIEWER PRIOR TO WHAT CHAPTER PICKED
            while(choice == 1){
                ifstream MyReadFile(reviewer); // WILL READ THE FILE REVIEWER .TXT
                int i = 0;
                cout << "\n--------------------------------------\n";
                 while(getline(MyReadFile, questions)){
                    cout << questions << endl;
                }
                cout << "\n--------------------------------------\n";
                cout << chapterFlavorText; // PRINT CHAPTER FLAVOR TEXT
                cout << "1. Review\n";
                cout << "2. Take Quiz\n"; // TAKE QUIZ
                cout << "3. Back\n";
                cout << "Input: ";
                cin >> choice;
                if(choice == 2 || choice == 3){
                	system("CLS");
					break;
				}
                system("CLS");
            }
            // THIS WILL DO READ THE FILE QUESTION PRIOR TO WHAT USER PICKED
            if(choice == 2){
                ifstream MyReadFile(file); // WILL READ THE FILE CHAPTER .TXT
                int score = 0;
                int index = 0;
                while(getline(MyReadFile, questions)){
                    cout << questions << endl;
                    // CHECK IF THE LINE IS * THEN PROCEED TO INPUT ANSWER
                    if(questions == "*"){
                        cout << "Your answer: ";
                        cin >> your_answer[index];
                        index++;
                    }
                }
                // LOOP THE USER'S ANSWERS
                for(int i=0;i<key_answer[chapter-1].length();i++){
                    upper = toupper(your_answer[i]);
                    cout << upper << ',';
                    if(key_answer[chapter-1][i] == upper){
                        score += 1;
                    }
                }
                // STORE SCORE IN CHAPTER_SCORES
                chapter_scores[chapter-1] = score;
                cout << "\nScore: " << chapter_scores[chapter-1] << endl;
                cout << "\n\n";
                system("pause");
                system("CLS");
            }
            if(choice == 3){
            	system("CLS");
			}
        }else if(choice == -1){
            break;
        }
	}while(true);

	return 0;
}
