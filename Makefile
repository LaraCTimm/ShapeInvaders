.PHONY: clean All

All:
	@echo "----------Building project:[ SFMLTestProject - Debug ]----------"
	@cd "SFMLTestProject" && "$(MAKE)" -f  "SFMLTestProject.mk"
clean:
	@echo "----------Cleaning project:[ SFMLTestProject - Debug ]----------"
	@cd "SFMLTestProject" && "$(MAKE)" -f  "SFMLTestProject.mk" clean
