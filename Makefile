.PHONY: clean All

All:
	@echo "----------Building project:[ ShapeInvaders - Debug ]----------"
	@"$(MAKE)" -f  "ShapeInvaders.mk"
clean:
	@echo "----------Cleaning project:[ ShapeInvaders - Debug ]----------"
	@"$(MAKE)" -f  "ShapeInvaders.mk" clean
