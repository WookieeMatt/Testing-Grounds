// Curiouser&Curiouser Games

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Gun.generated.h"

UCLASS()
class TESTINGGROUNDS_API AGun : public AActor
{
	GENERATED_BODY()

	/** Gun mesh: 1st person view (seen only by self) */
	UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
	class USkeletalMeshComponent* FP_Gun;

	/** Location on gun mesh where projectiles should spawn. */
	UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
	class USceneComponent* FP_MuzzleLocation;

public:	
	// Sets default values for this actor's properties
	AGun();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	/** Projectile class to spawn */
	UPROPERTY(EditDefaultsOnly, Category = Projectile)
	TSubclassOf<class ABallProjectile> ProjectileClass;

	/** Sound to play each time we fire */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
	class USoundBase* FireSound;

	/** AnimMontage to play each time we fire and aim*/
	UPROPERTY(EditAnywhere, BluePrintReadWrite, Category = Gameplay)
	class UAnimMontage* FireAnimation1P;
	UPROPERTY(EditAnywhere, BluePrintReadWrite, Category = Gameplay)
	class UAnimMontage* FireAnimation3P;

	UPROPERTY()
	class UAnimInstance* AnimInstance1P;
	UPROPERTY()
	class UAnimInstance* AnimInstance3P;

	/** Fires a projectile. */
	UFUNCTION(BlueprintCallable, Category = "Input")
	void OnFire();
	
};