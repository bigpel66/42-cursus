/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   guide.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 00:23:52 by jseo              #+#    #+#             */
/*   Updated: 2021/05/08 00:23:54 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	show_camera_guide(void)
{
	printf("=====Camera Mov===== \t  ");
	printf("=====Camera Rot===== \t  ");
	printf("=====Camera Cur=====\n");
	printf("Axis -X ---------> A \t  ");
	printf("Axis -X ---->   LEFT \t  ");
	printf("Zoom In ->    UP SCR\n");
	printf("Axis +X ---------> D \t  ");
	printf("Axis +X ---->  RIGHT \t  ");
	printf("Zoom Out -> DOWN SCR\n");
	printf("Axis -Y ---------> S \t  ");
	printf("Axis -Y ---->     UP \t  ");
	printf("Left Rot ->  1nd BTN\n");
	printf("Axis +Y ---------> W \t  ");
	printf("Axis +Y ---->   DOWN \t  ");
	printf("Flip Win ->  2nd BTN\n");
	printf("Axis -Z ---------> Q \t  ");
	printf("Axis -Z ---->  COMMA \n");
	printf("Axis +Z ---------> E \t  ");
	printf("Axis +Z ---->  SLASH \n");
	printf("==================== \t  ");
	printf("==================== \t  ");
	printf("====================\n\n");
}

static void	show_object_guide(void)
{
	printf("=====Object Mov===== \t  ");
	printf("=====Object Rot===== \t  ");
	printf("====Object Mode====\n");
	printf("Axis -X ---------> 1 \t  ");
	printf("Axis -X ---------> Z \t  ");
	printf("Filter   ----> ENTER\n");
	printf("Axis +X ---------> 2 \t  ");
	printf("Axis +X ---------> X \t  ");
	printf("Material ----> SPACE\n");
	printf("Axis -Y ---------> 3 \t  ");
	printf("Axis -Y ---------> C \t  ");
	printf("\n");
	printf("Axis +Y ---------> 4 \t  ");
	printf("Axis +Y ---------> V \t  ");
	printf("\n");
	printf("Axis -Z ---------> I \t  ");
	printf("Axis -Z ---------> K \n");
	printf("Axis +Z ---------> P \t  ");
	printf("Axis +Z --> SEMI COL \n");
	printf("==================== \t  ");
	printf("==================== \t  ");
	printf("====================\n\n");
}

static void	show_extra_guide(void)
{
	printf("=====Image Snap===== \t  ");
	printf("====Sphere Form===== \t  ");
	printf("===Program Exit=====\n");
	printf("Prev    ------->   N \t  ");
	printf("Switch  -------> DEL \t  ");
	printf("BYE BYE -------> ESC\n");
	printf("Next    ------->   M \t  ");
	printf("\n");
	printf("==================== \t  ");
	printf("==================== \t  ");
	printf("====================\n\n");
}

void		show_guide(void)
{
	ostream_title("Control Guide", 0);
	show_camera_guide();
	show_object_guide();
	show_extra_guide();
}
