/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetrimino_lists.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekantane <ekantane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 12:35:41 by ekantane          #+#    #+#             */
/*   Updated: 2022/02/01 16:15:39 by ekantane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>

// the HEADER file includes the structure of the node
// (the node is called t_tetris and the structure s_tetris)
// new_tetris is the actual piece, i know, sounds misleading
// data stores the information and next pointer holds the address of the next node

// the following function creates new nodes
// each node will consist of the DATA field and the field pointing to the NEXT node
// and obviously, null will end the list

// here we are using tet_id as an integer, meaning they are an array of coordinates

t_tetris *fillit_create(int *tet_id, char data_from_prepend)	// the function uses the coordinates and the modified data from prepend fuction
{
	t_tetris *new_tetris;
	
	new_t_tetris = (t_tetris*)malloc(sizeof(t_tetris));
	if (new_tetris != NULL)
	{
		new_tetris->data = data_from_prepend;
		new_tetris->tet_id = tet_id;			// we're using this like next
		new_tetris->next = NULL;
	}
	return (new_tetris);
}

// we also need a head pointer pointing to the first node of the list
// the head then points to a new node

node *fillit_prepend(int *tet_id, t_tetris *head, char data) 
{
	t_tetris *new_tetris;

	head = new_tetris;
	if (head->next != NULL)							// we can replace the empty head with an actual tetrimino
		head = head->next;
	new_tetris = fillit_create(tet_id, data);
	head->next = new_tetris;
	return	head;
}

// with these lists we can for example:
// - count the amount of possible tetriminos (by looping through all the nodes)
// -

// in addition to these we also need someting:
// - to translate the data into coordinates
// - & to store the tetriminos

// IN THE FUTURE:
// we compare the tetrimino id:s to user input id:s with strcmp

// the stack includes all the nodes, meaning all the tetriminos
// this is basically a copy from github, here for my educational purposes (this is probably the way how we feed the coordinates to the list):

t_tetris	*id_to_coord(t_tetris *stack)
{
	t_tetris	*head;
	t_tetris	*new_tetris;
	char		*tet_id;
	char		c;

	c = 'A';
	head = NULL;
	while (stack)
	{
		tet_id = stack->tet_id;
		if (head == NULL)
			head = fillit_create(TETRIMINO_ARRAY_HERE, c++);
		else
			new_tetris = fillit_prepend(TETRIMINO_ARRAY_HERE, head, c++);
		stack = stack->next;
	}
	return (head);
}
