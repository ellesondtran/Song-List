//Elleson Tran
//Roberts
//Song List Program
//Creates a list of songs that the user can interact with
//FINAL

#include <iostream>
#include <vector>
#include <string>

using namespace std;

//makes the first letter of the each word in a phrase uppercase
string upperCase(string &phrase){
  for(int x = 0; x < phrase.length(); x++){//goes through each letter in the phrase
    if(phrase.at(x) == ' '){//if there is a space, upcoming word
      phrase.at(x + 1) = toupper(phrase.at(x + 1));//capitalizes the next letter after the space
    }
  }

  phrase.at(0) = toupper(phrase.at(0)); //makes the first letter capital
  return phrase;
}

//adds a song to the playlist
vector<string> addSong(vector<string> &songList){
  int howMany;
  cout<<endl<<"How many songs do you want to add?:";
  cin>>howMany;

  cin.ignore();

  songList.resize(songList.size() + howMany);//resizes the vector to new size
  
  string song;

  for(int x = 0; x < howMany; x++){//loops to ask multiple times if needed
    cout<<endl<<"What song do you want to add?:";
    getline(cin, song);

    song = upperCase(song);
    
    songList[songList.size() - (howMany - x)] = song; //adds the song into the playlist
  }

  cout<<endl<<"Completed, added "<<howMany<<" new songs to the playlist!"<<endl;//gives confirmation

  return songList;
}

//prints the playlist
void viewList(vector<string> &songList){
  cout<<endl<<"Playlist:"<<endl;
  for(int x = 1; x <= songList.size(); x++){
    cout<<x<<". "<<songList[x-1]<<endl;
  }
}

//searches for the song
void searchSong(vector<string> &songList){

  string song;
  cout<<endl<<"Which song do you want to find?:";
  getline(cin, song);

  song = upperCase(song);
  
  bool found = false; //if it doesnt find the song, it keeps it false
  int num; //to keep the x value in the for loop

  for(int x = 0; x < songList.size(); x++){
    if(songList[x] == song){//if the song is found
      num = x;
      found = true;//sets found to true for the next if statement
    }
  }
  if(found == true){//prints the confirmation
    cout<<endl<<"The song is in our collection at index: "<<(num + 1)<<endl;
  }
  if(found == false){
    cout<<endl<<"That song is not in our collection."<<endl;
  }
}


int main() {
  
  int choice;

  vector<string> songList = {"Good Days - SZA", "Heartbreak Anniversary - Giveon", "Japanese Denim - Daniel Caesar", "34+35 - Ariana Grande", "Die For You - The Weeknd"};

  do{
    cout<<endl<<"1. Enter additional titles"<<endl<<"2. View full list of titles"<<endl<<"3. Search for a song"<<endl<<"4. Quit"<<endl;
    cin>>choice;

    cin.ignore();
    

    if(choice == 1){
      addSong(songList);

    }
    
    if(choice == 2){
      
      viewList(songList);
    }

    if(choice == 3){
      searchSong(songList);
    }
  }while(choice != 4);
  

}

