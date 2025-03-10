#include <iostream>
using namespace std;
class User{
    public:
    int user_id;
    string user_name;
    Post* post[10];
    int postcount=0;;
    User(){}
    User(int id,string name,int count):user_id(id),user_name(name),postcount(count){}
    void adduser(){
        cout <<"Enter Name" <<endl;
        getline(cin,user_name);
        cout <<"Enter user id";
        cin >>user_id;

    }
    void addpost(Post* p){
        if(postcount<10){
        post[postcount++]=p;
        }
        

    }
    void displayfunction(){
        cout <<"Name:" <<user_name <<endl;
        cout <<"User ID:" <<user_id <<endl;
        cout <<"Posts:";
        for (int i=0;i<postcount;i++){
            post[i]->displayfunction();
        }
    }



    
};
class Post{
    public:
    int postid;
    string content;
    Content* cont[10];
    int contentcount=0;;
    Post(){}
    Post(int p_id,string c):postid(p_id),content(c){}
    void addpostdetails(){
        cout <<"Enter Post ID:";
        cin >>postid;
        cout <<"Enter content:";
        cin >>content;
    }
    void addcontent(Content* c){
        if (contentcount<10){
        
        cont[contentcount++]=c;
        }
        }

    
    void displayfunction(){
        cout <<"Post ID:" <<postid <<endl;
        cout <<"Content:" <<content <<endl;
        cout <<"Content:";
        for (int i=0;i<contentcount;i++){
            cont[i]->displaycomment();
        }
    }
    


}; 

class Content{
    public:
    int commentid;
    string comment;
    User* author;
    
    Content(){}
    Content(int c_id,string cmnt):commentid(c_id),comment(cmnt){}
    void addcomment(){
        cout <<"Enter comment id:"; 
        cin >>commentid;
        cout <<"Enter comment:";
        cin >> comment;
    }
    void displaycomment(){
        cout <<"Comment ID:" <<commentid;
        cout <<"Comment:" <<comment;
        cout <<"Author:" <<author->user_name;

    } 

};
class SocialMediaPlatform{
    public:
    User u[10];
    int usercount;
    SocialMediaPlatform(){
        usercount=0;
    }
    void addUser(const User& u) {
        if (usercount < 10) {
            u[usercount++] = u;  // Storing user as an object
        }
    }
    

    void displayUsers() {
        cout << "Users on the Platform: " << endl;
        for (int i = 0; i < usercount; i++) {
            u[i].displayfunction();
        }
    }
};
