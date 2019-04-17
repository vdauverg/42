for f in srcs/*.c
do
	sed -i.backup 's/includes\/libft\.h/\.\.\/includes\/libft\.h/g' $f
done
