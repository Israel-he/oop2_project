#include "SoundManager.h"
#include <iostream>

SoundManager::SoundManager() {
    if (!m_appleBuffer.loadFromFile("assets/apple.wav"))
        std::cerr << "Failed to load apple.wav\n";

    if (!m_gameOverBuffer.loadFromFile("assets/gameover.wav"))
        std::cerr << "Failed to load gameover.wav\n";

    if (!m_victoryBuffer.loadFromFile("assets/teacher_win.ogg"))
        std::cerr << "Failed to load teacher_win.ogg\n";

    m_appleSound.setBuffer(m_appleBuffer);
    m_gameOverSound.setBuffer(m_gameOverBuffer);
    m_victorySound.setBuffer(m_victoryBuffer);

    if (!m_gameMusic.openFromFile("assets/game.ogg"))
        std::cerr << "Failed to load game.ogg\n";
}

void SoundManager::playAppleSound() {
    m_appleSound.play();
}

void SoundManager::playGameOverSound() {
    m_gameOverSound.play();
}

void SoundManager::playVictoryVoice() {
    m_victorySound.play();
}

void SoundManager::playGameMusic() {
    stopMusic();
    m_gameMusic.setLoop(true);
    m_gameMusic.play();
}

bool SoundManager::loadBackgroundMusic(const std::string& filepath) {
    stopMusic();
    if (!m_backgroundMusic.openFromFile(filepath)) {
        std::cerr << "Failed to load background music: " << filepath << "\n";
        return false;
    }
    return true;
}

void SoundManager::playBackgroundMusic(bool loop) {
    m_backgroundMusic.setLoop(loop);
    m_backgroundMusic.play();
}

void SoundManager::stopMusic() {
    m_gameMusic.stop();
    m_backgroundMusic.stop();
}