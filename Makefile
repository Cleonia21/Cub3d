NAME			=	cub3d
NAME_BONUS		=	cub3d_bonus

GCC				=	gcc -g3 -Wall -Wextra -Werror

DIR_LIBA		=	libft/
DIR_MINILIBX	=	mlx/
DIR_UTILS		=	utils/
DIR_MAP			=	cub_file/
DIR_GNL			=	get_next_line/
DIR_MANDATORY	=	mandatory/
DIR_BONUS		=	bonus/
DIR_SPRITES		=	sprites_bonus/

HEADERS			=	mandatory/cub3d.h mandatory/cub3d_structs.h cub_file/cub_file.h
BONUS_HEADER	=	bonus/cub3d_bonus.h bonus/sprites_bonus/sprite.h

SRC				=	main.c screen.c texture.c motion.c hook.c
SRC_UTILS		=	utils0.c utils1.c utils2.c utils3.c
SRC_MAP			=	read_map.c read_map_param.c checking_map_for_closure.c \
					cub_file.c color_param.c cub_file_utils.c make_map_mas.c write_map_list.c
SRC_GNL			=	get_next_line.c get_next_line_utils.c

SRC_SPRITES		=	sprites.c put_on_map.c sprite_utils.c
SRC_BONUS		=	main_bonus.c screen_bonus.c minimap_bonus.c texture_bonus.c motion_bonus.c \
					hook_bonus.c fog_bonus.c screenshot_bonus.c screenshot_utils_bonus.c

UTILS			=	$(addprefix $(DIR_UTILS), $(SRC_UTILS))
MAP				=	$(addprefix $(DIR_MAP), $(SRC_MAP))
GNL				=	$(addprefix $(DIR_GNL), $(SRC_GNL))
MANDATORY		=	$(addprefix $(DIR_MANDATORY), $(SRC))

BONUS			=	$(addprefix $(DIR_BONUS), $(SRC_BONUS))
SPRITES			=	$(addprefix $(DIR_BONUS), $(addprefix $(DIR_SPRITES), $(SRC_SPRITES)))

OBJ				=	$(MANDATORY:.c=.o) $(UTILS:.c=.o) $(MAP:.c=.o) $(GNL:.c=.o) $(LIBA:.c=.o)
OBJ_BONUS		=	$(BONUS:.c=.o) $(UTILS:.c=.o) $(MAP:.c=.o) $(GNL:.c=.o) $(LIBA:.c=.o) $(SPRITES:.c=.o)

all				:	mlx libft $(NAME) 

bonus			:	mlx libft $(NAME_BONUS) 
					
%.o				:	%.c
				$(GCC) -I mlx -c $< -o $@

$(NAME)			:	$(OBJ) $(HEADERS)
				@make -C mlx/
#				@echo "\033[0;35mКомпилю cub3d...\033[0;32m"
#				@echo "\033[0;35mСоздаю исполняемый файл...\033[0;32m"
				$(GCC) -o $(NAME) $(OBJ) libft/libft.a -Lmlx -lmlx -framework OpenGL -framework AppKit

$(NAME_BONUS)		:	$(OBJ_BONUS) $(HEADERS) $(BONUS_HEADER)
				@make -C mlx/
#				@echo "\033[0;35mКомпилю cub3d_bonus...\033[0;32m"
#				@echo "\033[0;35mСоздаю исполняемый файл...\033[0;32m"
				$(GCC) -o $(NAME_BONUS) $(OBJ_BONUS) libft/libft.a -Lmlx -lmlx -framework OpenGL -framework AppKit

xpm			:	mlx
				$(GCC) bonus/xpm_viewer_bonus.c -o xpm_viewer -Lmlx -lmlx -framework OpenGL -framework AppKit

mlx			:
				@echo "\033[0;35mКомпилю minilibx... \033[0;32m"
				@make -C mlx/
libft			:
				@echo "\033[0;35mКомпилю libft... \033[0;32m"
				@make -C $(DIR_LIBA)


clean			:
				@echo "\033[0;35mУдаляю объектные файлы...\033[0;31m"
				@make clean -C $(DIR_LIBA)
				@make clean -C $(DIR_MINILIBX)
				@echo "\033[0;35mcub3d: ЧИСТКА ОБЪЕКТНИКОВ...\033[0;31m"
				@rm -f $(OBJ)
				@rm -f $(OBJ_BONUS)

fclean			:	clean
				@echo "\033[0;35mУдаляю исполняемый файл...\033[0;31m"
				@rm -f $(NAME)
				@rm -f $(NAME_BONUS)
				@rm -f $(DIR_LIBA)/libft.a

re			:	fclean all

.PHONY			:	all libft clean fclean re
