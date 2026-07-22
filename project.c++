#include <iostream>
#include <string>
using namespace std;

class Node
{
public:

    string word;
    string meaning;

    int searchCount;

    Node *next;

    Node(string w,string m)
    {
        word = w;
        meaning = m;
        searchCount = 0;
        next = NULL;
    }
};

class Dictionary{
    Node* head;
public:
    Dictionary(){ 
	head=NULL;
	}

    bool isDuplicate(string key){
        Node* t=head;
        while(t){
            if(t->word==key)
			 return true;
            t=t->next;
        }
        return false;
    }

    void addWord(string w,string m){
        if(isDuplicate(w)){
            cout<<"\nWord already exists!\n";
            return;
        }
        Node* n=new Node(w,m);
        if(!head){
		head=n;
		}
        else{
            Node* t=head;
            while(t->next!=NULL)
			 t=t->next;
            t->next=n;
        }
        cout<<"\nWord Added Successfully.\n";
    }

    void displayDictionary(){
        if(!head){
            cout<<"\nDictionary is Empty.\n";
            return;
        }
        Node* t=head;
        cout<<"\n===== DICTIONARY =====\n";
        while(t){
            cout<<"Word    : "<<t->word<<"\n";
            cout<<"Meaning : "<<t->meaning<<"\n";
            cout<<"-------------------------\n";
            t=t->next;
        }
    }

    void searchWord(string key)
{
    Node *temp = head;

    while(temp != NULL)
    {
        if(temp->word == key)
        {
            temp->searchCount++;

            cout << "\nWord Found";
            cout << "\nMeaning : " << temp->meaning;

            cout << "\nSearch Count : "
                 << temp->searchCount
                 << endl;

            return;
        }

        temp = temp->next;
    }

    cout << "\nWord Not Found.\n";
}


  void mostSearchedWord()
{
    if(head == NULL)
    {
        cout << "\nDictionary is Empty.\n";
        return;
    }

    Node *temp = head;
    Node *most = head;

    while(temp != NULL)
    {
        if(temp->searchCount > most->searchCount)
        {
            most = temp;
        }

        temp = temp->next;
    }

    if(most->searchCount == 0)
    {
        cout << "\nNo word has been searched yet.\n";
        return;
    }

    cout << "\n======MOST SEARCHED WORD =======\n";

    cout << "\nWord : "
         << most->word;

    cout << "\nMeaning : "
         << most->meaning;

    cout << "\nSearched : "
         << most->searchCount
         << " times\n";
}
    void updateMeaning(string key){
        Node* t=head;
        while(t){
            if(t->word==key){
                cout<<"Current Meaning: "<<t->meaning<<"\n";
                cout<<"Enter New Meaning: ";
                getline(cin,t->meaning);
                cout<<"Updated Successfully!\n";
                return;
            }
            t=t->next;
        }
        cout<<"Word Not Found!\n";
    }

    void deleteWord(string key){
        if(!head){
		 cout<<"Dictionary Empty!\n";
		  return;
		   }
        if(head->word==key){
            Node* d=head;
		   head=head->next;
			 delete d;
            cout<<"Deleted Successfully!\n";
			 return;
        }
        Node* cur=head;
        while(cur->next && cur->next->word!=key)
		 cur=cur->next;
        if(!cur->next){
		 cout<<"Word Not Found!\n";
		  return;
		   }
        Node* d=cur->next;
        cur->next=d->next;
        delete d;
        cout<<"Deleted Successfully!\n";
    }

    void countWords(){
        int count=0;
        Node* t=head;
        while(t){
		count++;
		t=t->next;
		}
        cout<<"Total Words: "<<count<<"\n";
    }

  void sortDictionary()
{
    if(head == NULL)
    {
        cout << "\nDictionary is Empty.\n";
        return;
    }

    Node *i, *j;

    // Bubble Sort
    for(i = head; i != NULL; i = i->next)
    {
        for(j = i->next; j != NULL; j = j->next)
        {
            if(i->word > j->word)
            {
                //  word ko swap kro
                swap(i->word, j->word);

                //  meaning swap kro
                swap(i->meaning, j->meaning);

                // Swap search count
                swap(i->searchCount, j->searchCount);
            }
        }
    }

    cout << "\n====================================";
    cout << "\n Dictionary Sorted Successfully!";
    cout << "\n====================================";

    // Display Sorted Dictionary
    Node *temp = head;

    while(temp != NULL)
    {
        cout << "\nWord    : " << temp->word;
        cout << "\nMeaning : " << temp->meaning;
        cout << "\nSearch Count : " << temp->searchCount;
        cout << "\n------------------------------------";

        temp = temp->next;
    }

    cout << endl;
}

  void prefixSearch(string prefix)
{
    Node *temp = head;

    bool found = false;

    cout << "\nSuggestions\n";

    while(temp != NULL)
    {
        if(temp->word.substr(0,prefix.length()) == prefix)
        {
            cout << temp->word
                 << " -> "
                 << temp->meaning
                 << endl;

            found = true;
        }

        temp = temp->next;
    }

    if(!found)
    {
        cout << "\nNo Matching Words.\n";
    }
}

};

int main(){
    Dictionary dict;
    int choice;
    string word,meaning;

    do{
        cout<<"\n====== DICTIONARY MANAGEMENT SYSTEM ======\n";
        cout<<"1. Add Word\n2. Display Dictionary\n3. Search Word\n4. Update Meaning\n5. Delete Word\n6. Count Words\n7. Sort Dictionary\n8. mostsearchedwords\n9.prefix\n10.exit\n";
        cout<<"Enter Choice: ";
        cin>>choice;
        cin.ignore();

        switch(choice){
            case 1:
                cout<<"Enter Word: ";
                getline(cin,word);
                cout<<"Enter Meaning: ";
                getline(cin,meaning);
                dict.addWord(word,meaning);
                break;
            case 2:
                dict.displayDictionary();
                break;
            case 3:
                cout<<"Enter Word: ";
                getline(cin,word);
                dict.searchWord(word);
                break;
            case 4:
                cout<<"Enter Word: ";
                getline(cin,word);
                dict.updateMeaning(word);
                break;
                
           case 5:

          cout << "Enter Word: ";
          getline(cin, word);

         dict.deleteWord(word);

        cout << "\nUpdated Dictionary:\n";
        dict.displayDictionary();

         break;
            case 6:
                dict.countWords();
                break;
            case 7:
            
          dict.sortDictionary();

        dict.displayDictionary();

                break;
                
                case 8:

    dict.mostSearchedWord();

    break;
    
    case 9:

    cout << "\nEnter Prefix : ";

    getline(cin,word);

    dict.prefixSearch(word);

    break;
           
	 case 10:
        cout<<"Thank You!\n";
            break;
            default:
                cout<<"Invalid Choice!\n";
        }
        
    }while(choice!=10);
    return 0;
}

