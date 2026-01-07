#pragma once

#include <glm/ext/vector_float4.hpp>

struct Colors
{
    // ===== Whites / Blacks / Grays =====
    static inline const glm::vec4 White{1.0f, 1.0f, 1.0f, 1.0f};
    static inline const glm::vec4 Black{0.0f, 0.0f, 0.0f, 1.0f};
    static inline const glm::vec4 LightGray{0.8f, 0.8f, 0.8f, 1.0f};
    static inline const glm::vec4 Gray{0.5f, 0.5f, 0.5f, 1.0f};
    static inline const glm::vec4 DarkGray{0.2f, 0.2f, 0.2f, 1.0f};
    static inline const glm::vec4 Silver{0.75f, 0.75f, 0.75f, 1.0f};

    // ===== Reds =====
    static inline const glm::vec4 Red{1.0f, 0.0f, 0.0f, 1.0f};
    static inline const glm::vec4 BrightRed{1.0f, 0.2f, 0.2f, 1.0f};
    static inline const glm::vec4 LightRed{1.0f, 0.5f, 0.5f, 1.0f};
    static inline const glm::vec4 DarkRed{0.5f, 0.0f, 0.0f, 1.0f};
    static inline const glm::vec4 Crimson{0.86f, 0.08f, 0.24f, 1.0f};
    static inline const glm::vec4 Maroon{0.5f, 0.0f, 0.25f, 1.0f};

    // ===== Greens =====
    static inline const glm::vec4 Green{0.0f, 1.0f, 0.0f, 1.0f};
    static inline const glm::vec4 BrightGreen{0.2f, 1.0f, 0.2f, 1.0f};
    static inline const glm::vec4 LightGreen{0.6f, 1.0f, 0.6f, 1.0f};
    static inline const glm::vec4 DarkGreen{0.0f, 0.4f, 0.0f, 1.0f};
    static inline const glm::vec4 Lime{0.75f, 1.0f, 0.0f, 1.0f};
    static inline const glm::vec4 Olive{0.5f, 0.5f, 0.0f, 1.0f};
    static inline const glm::vec4 Mint{0.6f, 1.0f, 0.8f, 1.0f};
    static inline const glm::vec4 Teal{0.0f, 0.5f, 0.5f, 1.0f};

    // ===== Blues =====
    static inline const glm::vec4 Blue{0.0f, 0.0f, 1.0f, 1.0f};
    static inline const glm::vec4 BrightBlue{0.2f, 0.4f, 1.0f, 1.0f};
    static inline const glm::vec4 LightBlue{0.5f, 0.7f, 1.0f, 1.0f};
    static inline const glm::vec4 DarkBlue{0.0f, 0.0f, 0.4f, 1.0f};
    static inline const glm::vec4 Navy{0.0f, 0.0f, 0.5f, 1.0f};
    static inline const glm::vec4 SkyBlue{0.53f, 0.81f, 0.92f, 1.0f};
    static inline const glm::vec4 Cyan{0.0f, 1.0f, 1.0f, 1.0f};
    static inline const glm::vec4 Turquoise{0.25f, 0.88f, 0.82f, 1.0f};

    // ===== Yellows / Oranges =====
    static inline const glm::vec4 Yellow{1.0f, 1.0f, 0.0f, 1.0f};
    static inline const glm::vec4 LightYellow{1.0f, 1.0f, 0.6f, 1.0f};
    static inline const glm::vec4 Gold{1.0f, 0.84f, 0.0f, 1.0f};
    static inline const glm::vec4 Orange{1.0f, 0.5f, 0.0f, 1.0f};
    static inline const glm::vec4 DarkOrange{0.8f, 0.4f, 0.0f, 1.0f};

    // ===== Purples / Pinks =====
    static inline const glm::vec4 Purple{0.5f, 0.0f, 0.5f, 1.0f};
    static inline const glm::vec4 Violet{0.56f, 0.0f, 1.0f, 1.0f};
    static inline const glm::vec4 Magenta{1.0f, 0.0f, 1.0f, 1.0f};
    static inline const glm::vec4 Pink{1.0f, 0.75f, 0.8f, 1.0f};
    static inline const glm::vec4 HotPink{1.0f, 0.1f, 0.6f, 1.0f};

    // ===== Browns =====
    static inline const glm::vec4 Brown{0.6f, 0.3f, 0.1f, 1.0f};
    static inline const glm::vec4 DarkBrown{0.4f, 0.2f, 0.1f, 1.0f};
    static inline const glm::vec4 Chocolate{0.82f, 0.41f, 0.12f, 1.0f};
};
