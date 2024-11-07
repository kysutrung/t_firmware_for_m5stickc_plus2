#include "theMenu.h"
#include "yourPrograms.h"

//GLOBAL VAR
int QUIK_MODE = 1;
int MAIN_MENU_MODE = 1;
bool HAVE_ACCESS_THIS_MODE = 0;
bool ACTIVE_LAYER_02 = 0;
bool HAVE_ACCESS_THIS_PROG = 0;
int LAST_MAIN_MENU_MODE = 0;
int MENU_MODE_01 = 1;
int LAST_MENU_MODE_01 = 0;
int MENU_MODE_02 = 1;
int LAST_MENU_MODE_02 = 0;
int MENU_MODE_03 = 1;
int LAST_MENU_MODE_03 = 0;

//FUNCTIONS
void getButtonz(){
  StickCP2.update();
  if(StickCP2.BtnB.wasPressed()){
    StickCP2.Speaker.tone(8000, 20);
    if(HAVE_ACCESS_THIS_MODE == 0){
      MAIN_MENU_MODE++;
      if(MAIN_MENU_MODE > 4){
        MAIN_MENU_MODE = 1;
      }
    }
    else if(MAIN_MENU_MODE == 2 && HAVE_ACCESS_THIS_MODE == 1 && HAVE_ACCESS_THIS_PROG == 0){
      MENU_MODE_01++;
      if(MENU_MODE_01 > 7){
        MENU_MODE_01 = 1;
      }
    }
    else{
      MAIN_MENU_MODE++;
      MENU_MODE_01++;
      HAVE_ACCESS_THIS_MODE = 0;
      HAVE_ACCESS_THIS_PROG = 0;
      ACTIVE_LAYER_02 = 0;
    }


  }

  if(StickCP2.BtnA.wasPressed()){
    StickCP2.Speaker.tone(8000, 20);
    if(HAVE_ACCESS_THIS_MODE == 0){
      HAVE_ACCESS_THIS_MODE = 1;
    }

    if(HAVE_ACCESS_THIS_MODE == 1 && ACTIVE_LAYER_02 ==1){
      HAVE_ACCESS_THIS_PROG = 1;
    }
  }

  if(StickCP2.BtnA.wasReleased()){
    ACTIVE_LAYER_02 = 1;
  }
}

void setMainMenu(){
  getButtonz();
  int y_dot = 0;

  if(MAIN_MENU_MODE == 1){
    y_dot = 15;
    if(HAVE_ACCESS_THIS_MODE == 1){
      setQuikMode();
    }
  }
  if(MAIN_MENU_MODE == 2){
    y_dot = 45;
    if(HAVE_ACCESS_THIS_MODE == 1){
      setProgramsMenu();
    }
  }
  if(MAIN_MENU_MODE == 3){
    y_dot = 75;
    if(HAVE_ACCESS_THIS_MODE == 1){
      setGeneralSettingMode();
    }
  }
  if(MAIN_MENU_MODE == 4){
    y_dot = 105;
    if(HAVE_ACCESS_THIS_MODE == 1){
      setAboutDisplay();
    }
  }

  if(LAST_MAIN_MENU_MODE != MAIN_MENU_MODE && HAVE_ACCESS_THIS_MODE == 0){
    StickCP2.Display.clear();
    StickCP2.Display.setTextSize(1);
    StickCP2.Display.setCursor(40, 15);
    StickCP2.Display.printf("QUICK ACCESS");
    StickCP2.Display.setCursor(40, 45);
    StickCP2.Display.printf("PROGRAMS");
    StickCP2.Display.setCursor(40, 75);
    StickCP2.Display.printf("GENERAL SETTING");
    StickCP2.Display.setCursor(40, 105);
    StickCP2.Display.printf("ABOUT");

    StickCP2.Display.fillRect(12, y_dot, 15, 15, WHITE);

    LAST_MAIN_MENU_MODE = MAIN_MENU_MODE;
  }

}

void setQuikMode(){
  if(QUIK_MODE == 1){
    prog_a();
  }
  if(QUIK_MODE == 2){
    prog_b();
  }
  if(QUIK_MODE == 3){
    prog_c();
  }
  if(QUIK_MODE == 4){
    prog_d();
  }
  if(QUIK_MODE == 5){
    prog_e();
  }
  if(QUIK_MODE == 6){
    prog_f();
  }
  if(QUIK_MODE == 7){
    prog_g();
  }
}

void setProgramsMenu(){
  int y_dott = 0;

  if(MENU_MODE_01 == 1){
    y_dott = 15;
    if(HAVE_ACCESS_THIS_PROG == 1){
      prog_a();
    }
  }
  if(MENU_MODE_01 == 2){
    y_dott = 45;
    if(HAVE_ACCESS_THIS_PROG == 1){
      prog_b();
    }
  }
  if(MENU_MODE_01 == 3){
    y_dott = 75;
    if(HAVE_ACCESS_THIS_PROG == 1){
      prog_c();
    }
  }
  if(MENU_MODE_01 == 4){
    y_dott = 105;
    if(HAVE_ACCESS_THIS_PROG == 1){
      prog_d();
    }
  }
  if(MENU_MODE_01 == 5){
    y_dott = 15;
    if(HAVE_ACCESS_THIS_PROG == 1){
      prog_e();
    }
  }
  if(MENU_MODE_01 == 6){
    y_dott = 45;
    if(HAVE_ACCESS_THIS_PROG == 1){
      prog_f();
    }
  }
  if(MENU_MODE_01 == 7){
    y_dott = 75;
    if(HAVE_ACCESS_THIS_PROG == 1){
      prog_g();
    }
  }

  if(LAST_MENU_MODE_01 != MENU_MODE_01 && HAVE_ACCESS_THIS_PROG == 0 && MENU_MODE_01 < 5){
    StickCP2.Display.clear();
    StickCP2.Display.setTextSize(1);
    StickCP2.Display.setCursor(40, 15);
    StickCP2.Display.printf("PROGRAM 01");
    StickCP2.Display.setCursor(40, 45);
    StickCP2.Display.printf("PROGRAM 02");
    StickCP2.Display.setCursor(40, 75);
    StickCP2.Display.printf("PROGRAM 03");
    StickCP2.Display.setCursor(40, 105);
    StickCP2.Display.printf("PROGRAM 04");

    StickCP2.Display.fillRect(12, y_dott, 15, 15, WHITE);

    LAST_MENU_MODE_01 = MENU_MODE_01;
  }
  if(LAST_MENU_MODE_01 != MENU_MODE_01 && HAVE_ACCESS_THIS_PROG == 0 && MENU_MODE_01 > 4){
    StickCP2.Display.clear();
    StickCP2.Display.setTextSize(1);
    StickCP2.Display.setCursor(40, 15);
    StickCP2.Display.printf("PROGRAM 05");
    StickCP2.Display.setCursor(40, 45);
    StickCP2.Display.printf("PROGRAM 06");
    StickCP2.Display.setCursor(40, 75);
    StickCP2.Display.printf("PROGRAM 07");

    StickCP2.Display.fillRect(12, y_dott, 15, 15, WHITE);

    LAST_MENU_MODE_01 = MENU_MODE_01;
  }
}

void setGeneralSettingMode(){

}

void setAboutDisplay(){

}

//END FUNCTIONS