typedef union {
    struct {
        TSourceLoc line;
        union {
            TString *string;
            float f;
            int i;
            bool b;
        };
        TSymbol* symbol;
    } lex;
    struct {
        TSourceLoc line;
        TOperator op;
        union {
            TIntermNode* intermNode;
            TIntermNodePair nodePair;
            TIntermTyped* intermTypedNode;
            TIntermAggregate* intermAggregate;
        };
        union {
            TPublicType type;
            TQualifier qualifier;
            TFunction* function;
            TParameter param;
            TTypeLine typeLine;
            TTypeList* typeList;
        };
    } interm;
} YYSTYPE;
#define	ATTRIBUTE	258
#define	CONST_QUAL	259
#define	BOOL_TYPE	260
#define	FLOAT_TYPE	261
#define	INT_TYPE	262
#define	BREAK	263
#define	CONTINUE	264
#define	DO	265
#define	ELSE	266
#define	FOR	267
#define	IF	268
#define	DISCARD	269
#define	RETURN	270
#define	BVEC2	271
#define	BVEC3	272
#define	BVEC4	273
#define	IVEC2	274
#define	IVEC3	275
#define	IVEC4	276
#define	VEC2	277
#define	VEC3	278
#define	VEC4	279
#define	MATRIX2	280
#define	MATRIX3	281
#define	MATRIX4	282
#define	IN_QUAL	283
#define	OUT_QUAL	284
#define	INOUT_QUAL	285
#define	UNIFORM	286
#define	VARYING	287
#define	STRUCT	288
#define	VOID_TYPE	289
#define	WHILE	290
#define	SAMPLER1D	291
#define	SAMPLER2D	292
#define	SAMPLER3D	293
#define	SAMPLERCUBE	294
#define	SAMPLER1DSHADOW	295
#define	SAMPLER2DSHADOW	296
#define	SAMPLERRECTARB	297
#define	SAMPLERRECTSHADOWARB	298
#define	IDENTIFIER	299
#define	TYPE_NAME	300
#define	FLOATCONSTANT	301
#define	INTCONSTANT	302
#define	BOOLCONSTANT	303
#define	FIELD_SELECTION	304
#define	LEFT_OP	305
#define	RIGHT_OP	306
#define	INC_OP	307
#define	DEC_OP	308
#define	LE_OP	309
#define	GE_OP	310
#define	EQ_OP	311
#define	NE_OP	312
#define	AND_OP	313
#define	OR_OP	314
#define	XOR_OP	315
#define	MUL_ASSIGN	316
#define	DIV_ASSIGN	317
#define	ADD_ASSIGN	318
#define	MOD_ASSIGN	319
#define	LEFT_ASSIGN	320
#define	RIGHT_ASSIGN	321
#define	AND_ASSIGN	322
#define	XOR_ASSIGN	323
#define	OR_ASSIGN	324
#define	SUB_ASSIGN	325
#define	LEFT_PAREN	326
#define	RIGHT_PAREN	327
#define	LEFT_BRACKET	328
#define	RIGHT_BRACKET	329
#define	LEFT_BRACE	330
#define	RIGHT_BRACE	331
#define	DOT	332
#define	COMMA	333
#define	COLON	334
#define	EQUAL	335
#define	SEMICOLON	336
#define	BANG	337
#define	DASH	338
#define	TILDE	339
#define	PLUS	340
#define	STAR	341
#define	SLASH	342
#define	PERCENT	343
#define	LEFT_ANGLE	344
#define	RIGHT_ANGLE	345
#define	VERTICAL_BAR	346
#define	CARET	347
#define	AMPERSAND	348
#define	QUESTION	349

