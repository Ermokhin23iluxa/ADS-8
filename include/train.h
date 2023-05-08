// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TRAIN_H_
#define INCLUDE_TRAIN_H_

class Train {
 private:
  struct Cage {
    bool light;//lamp
		  Cage *next;
		  Cage *prev;
	  };
  int countOp;//счетчик шагов число переходов из вагона в вагон
	 Cage *head;//точка входа в поезд первый вагон
	 Cage *tail;//последний добавленный
	 int helpCount;
 public:
	 Train() :countOp(0), head(nullptr), tail(nullptr), helpCount(0) {}
	 void addCage(bool light);//добавить вагон с начальным состоянием лампочки
	 int getLength();//вычислить длинну поезда
	 int getOpCount();//вернуть число переходов из вагона в вагон
};
#endif  // INCLUDE_TRAIN_H_
