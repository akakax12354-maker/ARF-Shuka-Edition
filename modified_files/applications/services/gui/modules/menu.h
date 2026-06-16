/**
 * @file menu.h
 * GUI: Menu view module API
 */

#pragma once

#include <gui/view.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct Menu Menu;

typedef void (*MenuItemCallback)(void* context, uint32_t index);

Menu* menu_alloc(void);
void menu_free(Menu* menu);
View* menu_get_view(Menu* menu);

void menu_add_item(
    Menu* menu,
    const char* label,
    const Icon* icon,
    uint32_t index,
    MenuItemCallback callback,
    void* context);

void menu_reset(Menu* menu);
void menu_set_selected_item(Menu* menu, uint32_t index);

// ── Appearance configuration (call before the view is displayed) ──────────

/** Scroll wraps from last→first and first→last when enabled (default: true). */
void menu_set_scroll_loop(Menu* menu, bool enabled);

/** Slide animation between items when enabled; instant snap when disabled (default: false). */
void menu_set_scroll_anim(Menu* menu, bool enabled);

/** 4-column icon grid layout when enabled; scrolling list when disabled (default: false). */
void menu_set_layout_grid(Menu* menu, bool grid);

#ifdef __cplusplus
}
#endif
