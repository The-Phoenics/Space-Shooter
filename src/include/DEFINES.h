#pragma once

const int WINDOW_WIDTH  = 1000;
const int WINDOW_HEIGHT = 800;

static sf::Vector2f MIDDLE_OF_SCREEN(WINDOW_WIDTH / 2.f, WINDOW_HEIGHT / 2.f);

constexpr float BULLET_COUNT_UPDATE_TIME_INTERVAL = 0.18f;

constexpr const char* PATH_TO_FONT = "../res/font/dogicapixel.ttf";
constexpr float TEXT_SIZE = 15.f;