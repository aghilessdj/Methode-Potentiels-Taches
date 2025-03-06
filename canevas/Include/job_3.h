#pragma once

int get_job_oDegree(job_t * J);
void set_job_oDegree(job_t * J, int oDegree);
void incr_job_oDegree(job_t * J);
void decr_job_oDegree(job_t * J);

int get_job_rank(job_t * J);
void set_rank(job_t * J, int rank);

int titleJobCmp(job_t * J1, job_t * J2);
int iDegreeJobCmp(job_t * J1, job_t * J2);
int oDegreeJobCmp(job_t * J1, job_t * J2);
int rangJobCmp(job_t *J1, job_t * J2);
