#include "/home/projects/pillbox/src/libs/alib.h"

speaker sound(0);
button buttons[4];
display_info disp_info { 3, 4 };

GyverTM1637 disp(disp_info._clk, disp_info._dio);

time_struct _times[50];

String token = ""; // insert your token here

String user_id = ""; // insert your user id here

FastBot bot(token);

void message(FB_msg &message) {
  if (message.userID != user_id) {
    bot.sendMessage(unauthorized, message.userID);
    return;
  }

  String msg_first = "";

  int i = 0;
  while (message.text[i] != ' ' && i < message.text.length() - 1) msg_first += message.text[i++];
  
  uint8_t msg_type = get_msg_type(msg_first);

  switch (msg_type) {
    case message_type::START:
      bot_start(message.userID);
      break;
      
    case message_type::ADD_TIME:
      bot_add_time(message.userID, message.text);
      break;
    case message_type::DEL_TIME:
      bot_del_time(message.userID, message.text);
      break;
      
    case message_type::SET_INTERVAL:
      bot_set_interval(message.userID, message.text);
      break;
    case message_type::EDIT_INTERVAL:
      bot_edit_interval(message.userID, message.text);
      break;
    case message_type::DEL_INTERVAL:
      bot_del_interval(message.userID);
      break;
      
    case message_type::EDIT_MUSIC:
      bot_edit_music(message.userID);
      break;
    case message_type::DISABLE_MUSIC:
      bot_disable_music(message.userID);
      break;
    
    case message_type::HELP:
      bot_help(message.userID);
      break;
      
    default:
      bot.sendMessage(undefined, message.userID);
  }
}

void setup() {
  buttons[0].set_pin(5);
  buttons[1].set_pin(6);
  buttons[2].set_pin(7);
  buttons[3].set_pin(8);
}

void loop() {
  
}
