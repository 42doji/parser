//
// Created by dotte on 1/30/2025.
//

#ifndef CUB3D_H
#define CUB3D_H

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "libft.h"
#include "util_struct.h"
#include "map_struct.h"

t_map *init_map(void);
void error_handler(t_error error);

#endif //CUB3D_H
