#include "/home/projects/pillbox/src/libs/time.h"

uint8_t error = 42;

String hours = "0 \t 1 \t 2 \t 3 \n 4 \t 5 \t 6 \t 7 \n 8 \t 9 \t 10 \t 11 \n 12 \t 13 \t 14 \t 15 \n 16 \t 17 \t 18 \t 19 \n 20 \t 21 \t 22 \t 23";
String minutes = "00 \t 05 \t 10 \t 15 \n 20 \t 25 \t 30 \t 35 \n 40 \t 45 \t 50 \t 55";

enum message_type : uint8_t {
  START,
  
  ADD_TIME,
  DEL_TIME,
  
  SET_INTERVAL,
  EDIT_INTERVAL,
  DEL_INTERVAL,

  EDIT_MUSIC,
  DISABLE_MUSIC,
  
  HELP
};

uint8_t get_msg_type(String text) {
  if (text == "/start") return message_type::START;
  
  else if (text == "/add_time") return message_type::ADD_TIME;
  else if (text == "/del_time") return message_type::DEL_TIME;
  
  else if (text == "/set_interval") return message_type::SET_INTERVAL;
  else if (text == "/edit_interval") return message_type::EDIT_INTERVAL;
  else if (text == "/del_interval") return message_type::DEL_INTERVAL;
  
  else if (text == "/set_music") return message_type::EDIT_MUSIC;
  else if (text == "/disable_music") return message_type::DISABLE_MUSIC;
  
  else if (text == "/help") return message_type::HELP;
  else return error;
}

String unauthorized = "Вы не авторизованы. Для авторизации свяжитесь с создателем бота @vnik_v_tg";
String undefined = "Команда не распознана, попробуйте ещё раз или нажмите /help для помощи";

void bot_start(String &userID) {
  String text = "Это бот таблетницы. Здесь Вы можете настроить вашу таблетницу\n\n";
  text += "Для ознакомления с командами бота нажмите /help";

  bot.sendMessage(text, userID);
}

void bot_add_time(String &userID, Time* times) {
	  
