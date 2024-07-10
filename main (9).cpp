
#include <iostream>
#include <fstream>
#include <string>
#include <sstream> //string stream => convert object into string
#include <vector>

using namespace std;

class Book

int main()
{
private:
    int id;
    string title;
    string auther;
    
public:
    Book(){}
    Book(int i, string t, string a):id(i), title(t), author(a){}
    
    string to_string()
    {
        stringstream ss;
        ss << id <<", " <<title <<", "<<author;
        return ss.str();
    }
    
    static Book from_string(string& str)
    {
        stringstream ss(str);
        string item;
        vector<string>items;
        
        while(getline(ss, item, ','))
        {
            items.push_back(item);       
            
        }
        return Book(stoi(items[0], items[1], items[2]));
        
    }
    
};

class Library
{
private:
    string filename;
    
public:
    Library(string filename) : filename{filename) {}
    
    void addBook(Book& book)
    {
        ofstream file;
        file.open(filename, ios::app);
        
        if(file.is_open())
        {
            file << book.to_string()<<endl;
            file.close();
        }
        else
        {
            cerr<<"\nUnable to open file"<<endl;
        }
    }
    
    vector<Book> getbooks()
    {
        vector<Book> books;
        ifstream file(filename);
        string line;
        
        if(file.is_open())
        {
            while(getline(file, line))
            {
                books.push_back(Book::from_string(line));
            }
            file.close();
        }
        else
        {
            cerr<<"\nUnable to open file"<<endl;
        }
        
        return books;
    }
    
    void updateBook(int id, string& new_title, string& new_author)
    {
        vector<Book> books = getBooks();
        ofstream file(filename);
        if(file.is_open())
        {
            for(auto &book : books)
            {
                if(book.id == id)
                {
                    book.title = new_title;
                    book.author = new_author;
                }
                file <<book.to_string()<<endl;
            }
            file.close();
        }
        else
        {
            cerr<<"\nUnable to open file"<<endl;
        }
    }
    
    void deleteBook(int id)
    {
        vector<Book> books = getBooks ();
        ofstream file(filename);
        
        if(file.is_open())
        {
            for(auto &book : books)
            {
                if << (book.id != id)
                {
                    file << book.to_string()<<endl;
                }
            }
            file.close();
        }
        else
       {
        cerr<<"\nUnable to open"<<endl;
       }
    
    }
    
};

void displayMenu()
{
    cout<<"\n Library Management System"<<endl;
}

int main()
{
    
    

    return 0;
}    

    
