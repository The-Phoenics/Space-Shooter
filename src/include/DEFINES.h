#pragma once

inline sf::RenderWindow window(sf::VideoMode(1000, 800), "Space Shooter", sf::Style::Close);

const int WINDOW_WIDTH  = window.getSize().x;
const int WINDOW_HEIGHT = window.getSize().y;

static sf::Vector2f MIDDLE_OF_SCREEN(WINDOW_WIDTH / 2.f, WINDOW_HEIGHT / 2.f);

constexpr float BULLET_COUNT_UPDATE_TIME_INTERVAL = 0.18f;

constexpr const char* PATH_TO_FONT = "res/font/dogicapixel.ttf";

constexpr float TEXT_SIZE = 15.f;