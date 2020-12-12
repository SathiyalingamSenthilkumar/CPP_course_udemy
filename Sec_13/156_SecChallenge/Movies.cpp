/******************************************************************
 * Section 13 Challenge
 * Movies.h
 * 
 * Models a collection of Movies as a std::vector
 * 
 * ***************************************************************/
#include <iostream>
#include "Movies.h"

 /*************************************************************************
    Movies no-args constructor
**************************************************************************/
Movies::Movies() {
}

/*************************************************************************
    Movies destructor
**************************************************************************/
Movies::~Movies() {
}

  /*************************************************************************
    add_movie expects the name of the move, rating and watched count
    
    It will search the movies vector to see if a movie object already exists
    with the same name. 
    
    If it does then return false since the movie already exists
    Otherwise, create a movie object from the provided information
    and add that movie object to the movies vector and return true
    *********************************************************************/
bool Movies::add_movie(std::string name, std::string rating, int watched) {
  int is_present = 0;
  //Searching for the movie
  for(const auto & movie:movies){
    if(movie.get_name() == name){
      is_present = 1;
      break;
    }
  }

  if(is_present){
    return false;
  }
  else{
    //Movie is not present
    movies.push_back(Movie(name,rating,watched)); //Adding the movie
    return true;
  } 
}

 /*************************************************************************
    increment_watched expects the name of the move to increment the
    watched count
    
    It will search the movies vector to see if a movie object already exists
    with the same name. 
    If it does then increment that objects watched by 1 and return true.

    Otherwise, return false since then no movies object with the movie name
    provided exists to increment
    *********************************************************************/
bool Movies::increment_watched(std::string name) {

  int is_present = 0;
  //Searching for the movie
  for(auto & movie:movies){
    if(movie.get_name() == name){
      is_present = 1;
      //Increament the count by 1
      movie.increment_watched(); //It is passed by references
      break;
    }
  }

  if(is_present){
    //Movie is present
    return true;
  }
  else{
    //Movie is not present
    return false;
  }
}

/*************************************************************************
    display
    
    display all the movie objects in the movies vector.
    for each movie call the movie.display method so the movie
    object displays itself
    *********************************************************************/
void Movies::display() const {
  
  if(movies.size()==0){
    std::cout<<"Sorry, no movies to display.\n"<<std::endl;
  }
  else{//Printing the movies
    std::cout<<std::endl<<"================================================================"<<std::endl;
    for(const auto & movie:movies){ //Always use references -> To avoid making copies
      movie.display();
    }
    std::cout<<"================================================================"<<std::endl;
  }
}
