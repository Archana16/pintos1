#ifndef THREADS_SYNCH_H
#define THREADS_SYNCH_H

#include <list.h>
#include <stdbool.h>

/* A counting semaphore. */
struct semaphore {
	unsigned value; /* Current value. */
	struct list waiters; /* List of waiting threads. */
};

void sema_init(struct semaphore *, unsigned value);
void sema_down(struct semaphore *);
bool sema_try_down(struct semaphore *);
void sema_up(struct semaphore *);
void sema_self_test(void);

/* Lock. */
struct lock {
	struct thread *holder; /* Thread holding lock (for debugging). */
	struct semaphore semaphore; /* Binary semaphore controlling access. */
	struct list lock_list;
};
/* Elem in a list */
struct lock_list_node {
	struct thread * donee;/* thread that gets upgraded */
	int new_thread_priority; /* priority of current thread */
	int old_thread_priority; /* priority before donation */
	struct list_elem elem;

};

void lock_init(struct lock *);
void lock_acquire(struct lock *);
bool lock_try_acquire(struct lock *);
void lock_release(struct lock *);
bool lock_held_by_current_thread(const struct lock *);

/* One semaphore in a list. */
struct semaphore_elem {
	struct list_elem elem; /* List element. */
	struct semaphore semaphore; /* This semaphore. */
	int priority;
};

/* Condition variable. */
struct condition {
	struct list waiters; /* List of waiting threads. */
};

void cond_init(struct condition *);
void cond_wait(struct condition *, struct lock *);
void cond_signal(struct condition *, struct lock *);
void cond_broadcast(struct condition *, struct lock *);
void perform_donation(struct lock_list_node *node, struct lock *lock);
//to sort the elements of the lock's list
bool sort_new_thread_priority(struct list_elem *elem1, struct list_elem *elem2,
		void *aux);
bool sort_sema_with_priority(struct list_elem *elem1,struct list_elem *elem2,void *aux);

/* Optimization barrier.

 The compiler will not reorder operations across an
 optimization barrier.  See "Optimization Barriers" in the
 reference guide for more information.*/
#define barrier() asm volatile ("" : : : "memory")

#endif /* threads/synch.h */
