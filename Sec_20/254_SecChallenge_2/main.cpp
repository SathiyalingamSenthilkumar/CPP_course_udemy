// Section 20
// Challenge 2
//  Lists

#include <iostream>
#include <list>
#include <string>
#include <cctype>
#include <iomanip>
#include <limits>

class Song {
    friend std::ostream &operator<<(std::ostream &os, const Song &s);
    std::string name;
    std::string artist;
    int rating;
public:
    Song() = default;
    Song(std::string name, std::string artist, int rating)
            : name{name}, artist{artist}, rating{rating} {}
    std::string get_name() const {
        return name;
    }
    std::string get_artist() const {
        return artist;
    }
    int get_rating() const {
        return rating;
    }
    
    bool operator<(const Song &rhs) const  {
        return this->name < rhs.name;
    }
    
    bool operator==(const Song &rhs) const  {
        return this->name == rhs.name;
    }
};

std::ostream &operator<<(std::ostream &os, const Song &s) {
    os << std::setw(20) << std::left << s.name
       << std::setw(30) << std::left << s.artist
       << std::setw(2) << std::left << s.rating;
       return os;
}

void display_menu() {
    std::cout << "\nF - Play First Song" << std::endl;
    std::cout << "N - Play Next song" << std::endl;
    std::cout << "P - Play Previous song" << std::endl;
    std::cout << "A - Add and play a new Song at current location" << std::endl;
    std::cout << "L - List the current playlist" << std::endl;
    std::cout << "===============================================" << std::endl;
    std::cout << "Enter a selection (Q to quit): ";
}

void play_current_song(const Song &song) {
    // This function should display 
    // Playing: followed by the song that is playing
   
  std::cout<<"Playing:"<<std::endl;
  std::cout<<song<< std::endl;
}

void display_playlist(const std::list<Song> &playlist, const Song &current_song) {
  // This function should display the current playlist 
  // and then the current song playing.

  for(const auto& song:playlist){
    std::cout<<song<<std::endl;
  }

  std::cout<<std::endl<<"Current song:"<<std::endl;
  std::cout<<current_song<<std::endl;
}

int main() {

    std::list<Song> playlist{
            {"God's Plan",        "Drake",                     5},
            {"Never Be The Same", "Camila Cabello",            5},
            {"Pray For Me",       "The Weekend and K. Lamar",  4},
            {"The Middle",        "Zedd, Maren Morris & Grey", 5},
            {"Wait",              "Maroone 5",                 4},
            {"Whatever It Takes", "Imagine Dragons",           3}          
    };
    
    std::list<Song>::iterator current_song = playlist.begin();

    display_playlist(playlist,*current_song);

    char inp,inp_upper;
    do{
      display_menu();
      std::cin>>inp;
      inp_upper = toupper(inp);
      if(inp_upper == 'F'){
	std::cout<<std::endl<<"Playing first song"<<std::endl;
	current_song = playlist.begin(); // Setting to first
	play_current_song(*current_song);
      }
      else if(inp_upper == 'N'){
	std::cout<<std::endl<<"Playing next song"<<std::endl;
	if(*current_song == playlist.back()){
	  //Playing last song => Going back to beginning
	  std::cout<<"Wrapping around to play the first song"<<std::endl;
	  current_song = playlist.begin();
	}
	else{
	  //Playing the next song
	  current_song++;
	}
	play_current_song(*current_song);	
	
      }
      else if(inp_upper == 'P'){
	std::cout<<std::endl<<"Playing Previous song"<<std::endl;
	if(*current_song == playlist.front()){
	  //Playing first song => Going back to last song
	  std::cout<<"Wrapping around to play the last song"<<std::endl;
	  current_song = playlist.end(); // Pointing to end that is after the last elem
	  current_song--; // For the last elem
	}
	else{
	  //Playing the previous song
	  current_song--;
	}
	play_current_song(*current_song);	
      }
      else if(inp_upper == 'A'){
	std::cout<<std::endl<<"Adding and playing a new song at current location"<<std::endl;
	std::string name_new {};
	std::string artist_new {};
	int rating_new;
	//Clearing the cin => was causing trouble when using getline
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
	
	std::cout<<"Enter the song name: ";
	std::getline(std::cin,name_new);
        	
	std::cout<<"Enter the artist: ";
	std::getline(std::cin,artist_new);

	std::cout<<"Enter your rating (1-5): ";
	std::cin>>rating_new;

	playlist.insert(current_song,Song(name_new,artist_new,rating_new));
	current_song--; //Playing the newly added song
	play_current_song(*current_song);			
      }
      else if(inp_upper == 'L'){
	std::cout<<std::endl<<"Listing the current playlist:"<<std::endl;	
	display_playlist(playlist,*current_song);
      }
      else{
	std::cout<<"Invalid Input!! (Try a valid input)"<<std::endl;
      }
	
    }while(inp_upper != 'Q');

    std::cout << "Thanks for listening!" << std::endl;
    return 0;
}
