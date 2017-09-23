.PHONY: clean All

All:
	@echo "----------Building project:[ Game - Debug ]----------"
	@cd "Game" && "$(MAKE)" -f  "Game.mk"
clean:
	@echo "----------Cleaning project:[ Game - Debug ]----------"
	@cd "Game" && "$(MAKE)" -f  "Game.mk" clean
