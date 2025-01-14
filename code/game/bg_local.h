// Copyright (C) 1999-2000 Id Software, Inc.
//
// bg_local.h -- local definitions for the bg (both games) files

#define	MIN_WALK_NORMAL	0.7f		// can't walk on very steep slopes

#define	STEPSIZE		18

#define	TIMER_LAND		130
#define	TIMER_GESTURE	(34*66+50)

#define	OVERCLIP		1.001f

// all of the locals will be zeroed before each
// pmove, just to make damn sure we don't have
// any differences when running on client or server
typedef struct 
{
	vec3_t		forward, right, up;
	float		frametime;

	int			msec;

	qboolean	walking;
	qboolean	groundPlane;
	trace_t		groundTrace;

	float		impactSpeed;

	vec3_t		previous_origin;
	vec3_t		previous_velocity;
	int			previous_waterlevel;

	int			seed;
	qboolean	clipped; //japro nospeed ramp fix
} pml_t;

extern	pml_t		pml;

// movement parameters
extern	const	float	pm_stopspeed;
extern	const	float	pm_duckScale;
extern	const	float	pm_swimScale;
extern	const	float	pm_wadeScale;

extern	const	float	pm_accelerate;
extern	const	float	pm_airaccelerate;
extern	const	float	pm_wateraccelerate;
extern	const	float	pm_flyaccelerate;

extern	const	float	pm_friction;
extern	const	float	pm_waterfriction;
extern	const	float	pm_flightfriction;

//japro/dfmania movement parameters start
extern	const	float	pm_vq3_duckScale;

extern	const	float	pm_cpm_accelerate;
extern	const	float	pm_cpm_airaccelerate;
extern	const	float	pm_cpm_airstopaccelerate;
extern	const	float	pm_cpm_airstrafeaccelerate;
extern	const	float	pm_cpm_airstrafewishspeed;
extern	const	float	pm_cpm_aircontrol;
extern	const	float	pm_cpm_friction;

extern	const	float	pm_wsw_accelerate;
extern	const	float	pm_wsw_duckScale;

extern	const	float	pm_slick_accelerate;
extern	const	float	pm_slick_airstrafeaccelerate;

extern	const	float	pm_qw_airaccelerate;

//japro/dfmania movement parameters end

extern	int		c_pmove;

extern int forcePowerNeeded_1_02[NUM_FORCE_POWER_LEVELS][NUM_FORCE_POWERS];
extern int forcePowerNeeded_1_04[NUM_FORCE_POWER_LEVELS][NUM_FORCE_POWERS];
extern int (*forcePowerNeeded)[NUM_FORCE_POWERS];

// Had to add these here because there was no file access within the BG right now.
int		trap_FS_FOpenFile( const char *qpath, fileHandle_t *f, fsMode_t mode );
void	trap_FS_Read( void *buffer, int len, fileHandle_t f );
void	trap_FS_Write( const void *buffer, int len, fileHandle_t f );
void	trap_FS_FCloseFile( fileHandle_t f );

//PM anim utility functions:
qboolean PM_SaberInParry( int move );
qboolean PM_SaberInKnockaway( int move );
qboolean PM_SaberInReflect( int move );
qboolean PM_SaberInStart( int move );
qboolean PM_InSaberAnim( int anim );
qboolean PM_InKnockDown( playerState_t *ps );
qboolean PM_PainAnim( int anim );
qboolean PM_JumpingAnim( int anim );
qboolean PM_LandingAnim( int anim );
qboolean PM_SpinningAnim( int anim );
qboolean PM_InOnGroundAnim ( int anim );
qboolean PM_InRollComplete( playerState_t *ps, int anim );
int PM_AnimLength( int index, animNumber_t anim );

int PM_GetSaberStance(void);
float PM_GroundDistance(void);
qboolean PM_SomeoneInFront(trace_t *tr);
saberMoveName_t PM_SaberFlipOverAttackMove(trace_t *tr);
saberMoveName_t PM_SaberJumpAttackMove( void );

void PM_ClipVelocity( vec3_t in, vec3_t normal, vec3_t out, float overbounce );
void PM_AddTouchEnt( int entityNum );
void PM_AddEvent( int newEvent );

qboolean	PM_SlideMove( qboolean gravity );
void		PM_StepSlideMove( qboolean gravity );

void BG_CycleInven(playerState_t *ps, int direction);

void PM_StartTorsoAnim( int anim );
void PM_ContinueLegsAnim( int anim );
void PM_ForceLegsAnim( int anim );

void PM_BeginWeaponChange( int weapon );
void PM_FinishWeaponChange( void );

void PM_SetAnim(int setAnimParts,int anim,int setAnimFlags, int blendTime);

void PM_WeaponLightsaber(void);
void PM_SetSaberMove(short newMove);

void PM_SetForceJumpZStart(float value);
