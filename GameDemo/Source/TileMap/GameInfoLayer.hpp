#ifndef _GAME_INFO_LAYER_HPP
#define _GAME_INFO_LAYER_HPP

#include "axmol.h"

class GameInfoLayer : public ax::Layer
{
private:
  ax::Label *_label;

public:
  virtual bool init();
  static ax::Scene(scene);
  void menuCloseCallback(ax::Object *pSender);
  void numCollectedChanged(int numCollected);
};

#endif //_GAME_INFO_LAYER_HPP