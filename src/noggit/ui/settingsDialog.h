// This file is part of Noggit3, licensed under GNU General Public License (version 3).

#pragma once

#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QCheckBox>
#include <QSlider>
#include <QSpinBox>
#include <QLabel>

namespace noggit
{
  namespace ui
  {
    class settingsDialog : public QWidget
    {
      Q_OBJECT

    public:
      settingsDialog();

    private slots:
      void toggleGameProjectDisplay (bool);

      void setGameAndProjectPath();
      void setProjectPath();
      void setAntialiasing (bool value);
      void setMaximizedShow (bool value);
      void setMaximizedAppShow (bool value);
      void setProjectExplorerShow (bool value);
      void setViewDistance (int value);

      void settingChanged (const QString& key, const QVariant& value);

    private:
      QLabel* currentGamePath;
      QPushButton* changeGamePathButton;

      QLabel* projectPathLabel;
      QLabel* currentProjectPath;
      QPushButton* changeProjectPathButton;
      QCheckBox* addProjectPathCheckBox;

      QSlider* viewDistanceSlider;
      QSpinBox* viewDistanceSpinBox;

      QCheckBox* antialiasingCheckBox;
      QCheckBox* maximizedShowCheckBox;
      QCheckBox* maximizedAppShowCheckBox;
      QCheckBox* projectExplorerShowCheckBox;
    };
  }
}
