/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaniatt <tbaniatt@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 20:33:57 by tbaniatt          #+#    #+#             */
/*   Updated: 2025/02/09 20:37:39 by tbaniatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>



typedef struct s_philo
{
        int				id;
        int				left_fork;
        int				right_fork;
        int				eat_count;
        long long		last_eat;
        pthread_t		thread;
        struct s_data	*data;
}				t_philo;




#endif