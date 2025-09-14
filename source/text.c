#include "text.h"

Font Text_LoadFont(const char* path) {
	Font ret;
	ret.texture = Backend_LoadTexture(path);

	Vec2 size      = Backend_GetTextureSize(ret.texture);
	ret.charWidth  = size.x / 16;
	ret.charHeight = size.y / 16;
	return ret;
}

void Text_FreeFont(Font* font) {
	Backend_FreeTexture(font->texture);
}

void Text_Render(Font* font, const char* string, int x, int y) {
	Rect dest;
	dest.x = x;
	dest.y = y;
	dest.w = font->charWidth;
	dest.h = font->charHeight;

	Rect src;
	src.w = font->charWidth;
	src.h = font->charHeight;
	Backend_DrawTexture(font->texture, NULL, NULL, NULL);

// 	for (size_t i = 0; i < strlen(string); ++ i) {
// 		src.x = ((int) (string[i] % 16)) * font->charWidth;
// 		src.y = ((int) (string[i] / 16)) * font->charHeight;
// 
// 		Backend_DrawTexture(font->texture, NULL, &src, &dest);
// 		dest.x += font->charWidth;
// 	}
}
