/*-------------------------------------------------------------------------
 *
 * pg_database.h
 *	  definition of the system "database" relation (pg_database)
 *	  along with the relation's initial contents.
 *
 *
 * Portions Copyright (c) 1996-2013, PostgreSQL Global Development Group
 * Portions Copyright (c) 1994, Regents of the University of California
 *
 * src/include/catalog/pg_database.h
 *
 * NOTES
 *	  the genbki.pl script reads this file and generates .bki
 *	  information from the DATA() statements.
 *
 *-------------------------------------------------------------------------
 */
#ifndef PG_DATABASE_H
#define PG_DATABASE_H

#include "catalog/genbki.h"

/* ----------------
 *		pg_database definition.  cpp turns this into
 *		typedef struct FormData_pg_database
 * ----------------
 */
#define DatabaseRelationId	1262
#define DatabaseRelation_Rowtype_Id  1248

CATALOG(pg_database,1262) BKI_SHARED_RELATION BKI_ROWTYPE_OID(1248) BKI_SCHEMA_MACRO
{
	NameData	datname;		/* database name */
	Oid			datdba;			/* owner of database */
	int32		encoding;		/* character encoding */
	NameData	datcollate;		/* LC_COLLATE setting */
	NameData	datctype;		/* LC_CTYPE setting */
	bool		datistemplate;	/* allowed as CREATE DATABASE template? */
	bool		datallowconn;	/* new connections allowed? */
	int32		datconnlimit;	/* max connections allowed (-1=no limit) */
	Oid			datlastsysoid;	/* highest OID to consider a system OID */
	TransactionId datfrozenxid; /* all Xids < this are frozen in this DB */
	TransactionId datminmxid;	/* all multixacts in the DB are >= this */
	Oid			dattablespace;	/* default table space for this DB */
	int32		hashmethod;		/* hashmethod for dist of tables in the db */
#ifdef CATALOG_VARLEN			/* variable-length fields start here */
	aclitem		datacl[1];		/* access permissions */
#endif
} FormData_pg_database;

/* GPDB added foreign key definitions for gpcheckcat. */
FOREIGN_KEY(datdba REFERENCES pg_authid(oid));
FOREIGN_KEY(dattablespace REFERENCES pg_tablespace(oid));

/* ----------------
 *		Form_pg_database corresponds to a pointer to a tuple with
 *		the format of pg_database relation.
 * ----------------
 */
typedef FormData_pg_database *Form_pg_database;

/* ----------------
 *		compiler constants for pg_database
 * ----------------
 */
#define Natts_pg_database				13
#define Anum_pg_database_datname		1
#define Anum_pg_database_datdba			2
#define Anum_pg_database_encoding		3
#define Anum_pg_database_datcollate		4
#define Anum_pg_database_datctype		5
#define Anum_pg_database_datistemplate	6
#define Anum_pg_database_datallowconn	7
#define Anum_pg_database_datconnlimit	8
#define Anum_pg_database_datlastsysoid	9
#define Anum_pg_database_datfrozenxid	10
<<<<<<< HEAD
#define Anum_pg_database_dattablespace	11
#define Anum_pg_database_hashmethod		12
#define Anum_pg_database_datacl			13

/*
 * The value for hashmethod col is defined in cdb/cdbhash.h
 * the magic number 1 here means JUMP_HASH_METHOD
 */
DATA(insert OID = 1 (  template1 PGUID ENCODING "LC_COLLATE" "LC_CTYPE" t t -1 0 0 1663 1 _null_));
=======
#define Anum_pg_database_datminmxid		11
#define Anum_pg_database_dattablespace	12
#define Anum_pg_database_datacl			13

DATA(insert OID = 1 (  template1 PGUID ENCODING "LC_COLLATE" "LC_CTYPE" t t -1 0 0 1 1663 _null_));
>>>>>>> e472b921406407794bab911c64655b8b82375196
SHDESCR("default template for new databases");
#define TemplateDbOid			1

#endif   /* PG_DATABASE_H */
