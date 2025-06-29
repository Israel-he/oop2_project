#pragma once
#include <SFML/Audio.hpp>
#include <string>

class SoundManager {
public:
    SoundManager();

    void playAppleSound();
    void playGameOverSound();
    void playVictoryVoice();

    void playGameMusic();
    bool loadBackgroundMusic(const std::string& filepath);
    void playBackgroundMusic(bool loop = true);
    void stopMusic();

private:
    sf::SoundBuffer m_appleBuffer;
    sf::SoundBuffer m_gameOverBuffer;
    sf::SoundBuffer m_victoryBuffer;

    sf::Sound m_appleSound;
    sf::Sound m_gameOverSound;
    sf::Sound m_victorySound;

    sf::Music m_gameMusic;
    sf::Music m_backgroundMusic;
};