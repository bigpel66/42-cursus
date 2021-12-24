/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 17:41:44 by jseo              #+#    #+#             */
/*   Updated: 2021/12/24 13:33:18 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


void padding ( char ch, int n )
{
    int i;

    for ( i = 0; i < n; i++ )
        putchar ( ch );
}

void print_node ( t_node *root, int level )
{

    if ( root == NULL )
    {
        padding ( '\t', level );
        puts ( "NIL" );

    }
    else
    {
        print_node ( root->right, level + 1 );
        padding ( '\t', level );
        if(root->color == BLACK)
        {
            printf ( "(%s)\n", (char*)(root->key) );
        }
        else
            printf ( "%s\n",(char*)(root->key) );
        print_node ( root->left, level + 1 );
    }
}

void print_tree(t_rb* tree)
{
    print_node(tree->root,0);
    printf("-------------------------------------------\n");
}

int compare(void *key_a, void *key_b)
{
	return (jstrncmp((char *)key_a, (char *)key_b, BUFFER_SIZE));
}

int main(int argc, char **argv, char **envp)
{
	(void)argc;
	(void)argv;
	(void)envp;
	t_rb *rb = rb_init(compare);
	rb_insert(rb, "a", "1");
	rb_insert(rb, "b", "2");
	rb_insert(rb, "x4444", "3");
	rb_insert(rb, "x22", "4");
	rb_insert(rb, "x3", "5");
	rb_insert(rb, "x2", "5");
	rb_insert(rb, "x", "51");
	// rb_insert(rb, "c", "3");
	// rb_insert(rb, "a", "1");
	// rb_insert(rb, "abb", "2");
	// rb_insert(rb, "bbbb", "2");
	// rb_insert(rb, "bxx", "2");
	// rb_insert(rb, "avvcx", "3");
	// rb_insert(rb, "d", "3");
	// rb_insert(rb, "g", "3");
	// rb_insert(rb, "z", "3");
	// rb_insert(rb, "ggggg", "3");
	// rb_insert(rb, "ggg5", "3");
	// rb_insert(rb, "x", "3");
	// printf("Before\n");
	// rb_order(rb, INORDER);
	print_tree(rb);
	// t_rb *x = rb_search(rb, "x");
	// rb = rb_delete(rb, x);
	// x = rb_search(rb, "a");
	// rb = rb_delete(rb, x);

	// printf("After\n");
	// rb_order(rb, INORDER);
	// int i = -1;
	// while (*envp != NULL && ++i >= 0)
	// {
	// 	printf("%d: %s\n", i, *envp++);
	// }
	return (VALID);
}
