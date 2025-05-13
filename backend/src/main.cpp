#include "crow_all.h"
#include "auth.hpp"
#include "lobby.hpp"
#include "game_manager.hpp"

int main() {
  crow::SimpleApp app;

  // Serve static frontend
  app.route_dynamic("/")
     .static_file("frontend/public/index.html");
  app.route_dynamic("/<path>")
     .static_file("frontend/public/{path}");

  // Auth endpoints
  CROW_ROUTE(app, "/api/signup").methods("POST"_method)(handle_signup);
  CROW_ROUTE(app, "/api/login").methods("POST"_method)(handle_login);

  // Lobby endpoints
  CROW_ROUTE(app, "/api/lobbies").methods("GET"_method)(get_lobbies);
  CROW_ROUTE(app, "/api/lobbies").methods("POST"_method)(create_lobby);

  // WebSocket for chat (per lobby)
  CROW_ROUTE(app, "/ws/chat/<string>").websocket()
    .onopen(on_chat_open)
    .onmessage(on_chat_message)
    .onclose(on_chat_close);

  // Game WebSocket (per lobby + game type)
  CROW_ROUTE(app, "/ws/game/<string>/<string>").websocket()
    .onopen(on_game_open)
    .onmessage(on_game_message)
    .onclose(on_game_close);

  app.port(8080).multithreaded().run();
}
