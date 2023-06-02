/*
** EPITECH PROJECT, 2023
** csl_void
** File description:
** csl_void
*/

#ifndef CSL_VOID
    #define CSL_VOID
    #include "csl_struct.h"
    base_t *csl_add_base(base_t *start, void *data);
    void csl_add_bgn(base_t **tail, void *data);
    void csl_add_end(base_t *tail, void *data);
    void csl_rm_mid(base_t *head);
    void csl_add_mid(base_t *mid, void *data);
    void csl_rm_base(base_t *base);
    void csl_rm_bgn(base_t **head);
    void csl_rm_chain(base_t *base);
    void csl_rm_end(base_t *tail);
    void csl_rm_mid(base_t *head);
#endif /* !CSL_VOID */
