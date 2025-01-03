#pragma once

#include <Types.h>

namespace i18n {
enum class Lang
{
  en,
  de,
  ru,
  nl,
  pl,
  fr,
  it,
  zh
};
}

extern const i18n::Lang g_lang;

extern const int MAX_MESSAGES_ON_MAP_BOTTOM;

extern const int BOBBYR_ITEMS_BOUGHT_X;

auto GetLanguagePrefix() -> const STR;
