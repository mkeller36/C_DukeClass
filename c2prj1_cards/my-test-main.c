#include "cards.h"
#include <stdio.h>                                           
#include <assert.h>                                          
#include <stdlib.h> 

void assert_card_valid(card_t c) {
  char value_let = c.value;
  char suit_let = c.suit;
  assert((value_let >= '2' && value_let <= '9') || value_let == '0' || value_let == 'J' || value_let == 'Q' || value_let == 'K' || value_let == 'A');
  assert(suit_let == 's' || suit_let == 'h' || suit_let == 'd' || suit_let == 'c');  
}

const char * ranking_to_string(hand_ranking_t r) {
  char rank = "__";
  switch(r){
  case STRAIGHT_FLUSH: rank = "straight Flush"; break;
  case FOUR_OF_A_KIND: rank = "four of a kind"; break;
  case FULL_HOUSE: rank = "full house"; break
  case FLUSH: rank = "flush"; break
  case STRAIGHT: rank = "straight"; break;
  case THREE_OF_A_KIND: rank = "three of a kind"; break;
  case TWO_PAIR: rank = "two pair"; break;
  case PAIR: rank = "pair"; break;
  case NOTHING: rank = "nothing"; break;
  return "";
}

char value_letter(card_t c) {
  int val = '*';
  switch(c.value){
  case '2':
  case 2: val = '2'; break;
  case '3':
  case 3: val = '3'; break;
  case '4':
  case 4: val = '4'; break;
  case '5':
  case 5: val = '5'; break;
  case '6':
  case 6: val = '6'; break;
  case '7':
  case 7: val = '7'; break;
  case '8':
  case 8: val = '8'; break;
  case '9':
  case 9: val = '9'; break;
  case '0':
  case 10: val = '0'; break;
  case 'J':
  case VALUE_JACK: val = 'J'; break;
  case 'Q':
  case VALUE_QUEEN: val = 'Q'; break;
  case 'K':
  case VALUE_KING: val = 'K'; break;
  case 'A':
  case VALUE_ACE: val = 'A'; break;
  }


  return val;
}

char suit_letter(card_t c) {
  suit_t suit = '*';
  switch(c.suit){
  case SPADES: suit = 's'; break;
  case HEARTS: suit = 'h'; break;
  case DIAMONDS: suit = 'd'; break;
  case CLUBS: suit = 'c'; break;
  case NUM_SUITS: suit = '4'; break;
  }
  return suit;
}

void print_card(card_t c) {
  printf("%c%c\n",c.value,c.suit);
}

card_t card_from_letters(char value_let, char suit_let) {
  card_t temp;
  temp.suit = suit_let;
  temp.value = value_let;
  assert_card_valid(temp);
  return temp;
}
card_t card_from_num(unsigned c) {
  card_t temp;
  temp.value =(c % 13) + 2;
  temp.suit = (c / 13);
  temp.suit = suit_letter(temp);
  temp.value = value_letter(temp);
  assert_card_valid(temp);
  return temp;
}

int main(void){ 
  int i = 0;
  card_t tempi = card_from_letters('3','s');
  print_card(tempi);
  for(i=0;i<52;i++){
    printf("%02i: ",i);
    card_t temp1 = card_from_num(i);
    print_card(temp1);
    card_t temp = card_from_letters(temp1.value,temp1.suit);
    print_card(temp);
  }
}


