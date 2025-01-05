-- phpMyAdmin SQL Dump
-- version 4.9.5deb2
-- https://www.phpmyadmin.net/
--
-- Host: localhost:3306
-- Generation Time: Jan 02, 2025 at 11:00 AM
-- Server version: 10.3.39-MariaDB-0ubuntu0.20.04.2
-- PHP Version: 7.4.3-4ubuntu2.24

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET AUTOCOMMIT = 0;
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `s823_storylines_samp`
--

-- --------------------------------------------------------

--
-- Table structure for table `ajail_logs`
--

CREATE TABLE `ajail_logs` (
  `id` int(11) NOT NULL,
  `JailedDBID` int(11) NOT NULL,
  `JailedName` varchar(32) NOT NULL,
  `Reason` varchar(128) NOT NULL,
  `Date` varchar(90) NOT NULL,
  `JailedBy` varchar(32) NOT NULL,
  `Time` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COLLATE=latin1_swedish_ci;

--
-- Dumping data for table `ajail_logs`
--

INSERT INTO `ajail_logs` (`id`, `JailedDBID`, `JailedName`, `Reason`, `Date`, `JailedBy`, `Time`) VALUES
(25, 78, 'Brayn Conwell', 'tester', 'December 26, 2024 22:20:44', 'randz', 1),
(26, 78, 'Brayn Conwell', 'tester', 'December 26, 2024 22:22:15', 'randz', 1),
(27, 78, 'Brayn Conwell', 'kontol', 'December 29, 2024 09:39:46', 'randz', 20);

-- --------------------------------------------------------

--
-- Table structure for table `bannedlist`
--

CREATE TABLE `bannedlist` (
  `id` int(11) NOT NULL,
  `CharacterDBID` int(11) NOT NULL,
  `MasterDBID` int(11) NOT NULL,
  `CharacterName` varchar(32) NOT NULL,
  `Reason` varchar(128) NOT NULL,
  `Date` varchar(90) NOT NULL,
  `BannedBy` varchar(32) NOT NULL,
  `IpAddress` varchar(60) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COLLATE=latin1_swedish_ci;

-- --------------------------------------------------------

--
-- Table structure for table `ban_logs`
--

CREATE TABLE `ban_logs` (
  `id` int(11) NOT NULL,
  `CharacterDBID` int(11) NOT NULL,
  `MasterDBID` int(11) NOT NULL,
  `CharacterName` varchar(32) NOT NULL,
  `Reason` varchar(128) NOT NULL,
  `BannedBy` varchar(32) NOT NULL,
  `Date` varchar(90) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COLLATE=latin1_swedish_ci;

-- --------------------------------------------------------

--
-- Table structure for table `businesses`
--

CREATE TABLE `businesses` (
  `BusinessDBID` int(11) NOT NULL,
  `BusinessOwnerDBID` int(11) NOT NULL DEFAULT 0,
  `BusinessInteriorX` float NOT NULL DEFAULT 0,
  `BusinessInteriorY` float NOT NULL DEFAULT 0,
  `BusinessInteriorZ` float NOT NULL DEFAULT 0,
  `BusinessInteriorWorld` int(11) NOT NULL DEFAULT 0,
  `BusinessInteriorIntID` int(11) NOT NULL DEFAULT 0,
  `BusinessEntranceX` float NOT NULL DEFAULT 0,
  `BusinessEntranceY` float NOT NULL DEFAULT 0,
  `BusinessEntranceZ` float NOT NULL DEFAULT 0,
  `BusinessName` varchar(90) NOT NULL DEFAULT 'Nameless',
  `BusinessType` int(11) NOT NULL DEFAULT 0,
  `BusinessLocked` tinyint(1) NOT NULL DEFAULT 0,
  `BusinessEntranceFee` int(11) NOT NULL DEFAULT 1,
  `BusinessLevel` int(11) NOT NULL DEFAULT 0,
  `BusinessMarketPrice` int(11) NOT NULL DEFAULT 5000,
  `BusinessCashbox` int(11) NOT NULL DEFAULT 0,
  `BusinessStock` int(11) NOT NULL DEFAULT 0,
  `BusinessMapIcon` int(11) NOT NULL DEFAULT 0,
  `BusinessPointX` float NOT NULL DEFAULT 0,
  `BusinessPointY` float NOT NULL DEFAULT 0,
  `BusinessPointZ` float NOT NULL DEFAULT 0,
  `BusinessRobberyTime` int(11) NOT NULL DEFAULT 0,
  `BusinessShipments` int(11) NOT NULL DEFAULT 0,
  `BusinessAmount` int(11) NOT NULL DEFAULT 0,
  `BusinessFuelX` float NOT NULL DEFAULT 0,
  `BusinessFuelY` float NOT NULL DEFAULT 0,
  `BusinessFuelZ` float NOT NULL DEFAULT 0,
  `BusinessActorX` float NOT NULL DEFAULT 0,
  `BusinessActorY` float NOT NULL DEFAULT 0,
  `BusinessActorZ` float NOT NULL DEFAULT 0,
  `BusinessActorA` float NOT NULL DEFAULT 0,
  `BusinessProducts1` int(11) NOT NULL DEFAULT 0,
  `BusinessProducts2` int(11) NOT NULL DEFAULT 0,
  `BusinessProducts3` int(11) NOT NULL DEFAULT 0,
  `BusinessProducts4` int(11) NOT NULL DEFAULT 0,
  `BusinessProducts5` int(11) NOT NULL DEFAULT 0,
  `BusinessProducts6` int(11) NOT NULL DEFAULT 0
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COLLATE=latin1_swedish_ci;

--
-- Dumping data for table `businesses`
--

INSERT INTO `businesses` (`BusinessDBID`, `BusinessOwnerDBID`, `BusinessInteriorX`, `BusinessInteriorY`, `BusinessInteriorZ`, `BusinessInteriorWorld`, `BusinessInteriorIntID`, `BusinessEntranceX`, `BusinessEntranceY`, `BusinessEntranceZ`, `BusinessName`, `BusinessType`, `BusinessLocked`, `BusinessEntranceFee`, `BusinessLevel`, `BusinessMarketPrice`, `BusinessCashbox`, `BusinessStock`, `BusinessMapIcon`, `BusinessPointX`, `BusinessPointY`, `BusinessPointZ`, `BusinessRobberyTime`, `BusinessShipments`, `BusinessAmount`, `BusinessFuelX`, `BusinessFuelY`, `BusinessFuelZ`, `BusinessActorX`, `BusinessActorY`, `BusinessActorZ`, `BusinessActorA`, `BusinessProducts1`, `BusinessProducts2`, `BusinessProducts3`, `BusinessProducts4`, `BusinessProducts5`, `BusinessProducts6`) VALUES
(15, 0, 1470.7, 1562.97, 108.377, 8030, 11, 1248.82, 365.373, 19.5547, 'Unknown', 4, 0, 0, 0, 0, 0, 0, 0, 1473.9, 1567.96, 108.377, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(16, 0, 1439.55, 1562.97, 108.377, 16013, 11, 122.412, -294.581, 1.57812, 'Unknown', 3, 0, 0, 0, 0, 0, 0, 0, 1440.35, 1576.02, 108.377, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(17, 78, 207.726, -110.823, 1005.13, 4937, 15, 2244.5, -1665.01, 15.4766, 'Ganton Clothes Conwell.co', 8, 0, 100, 0, 5000000, 60100, 88, 45, 207.742, -99.5688, 1005.35, 0, 0, 0, 0, 0, 0, 207.811, -98.7037, 1005.26, 180.074, 3000, 2000, 0, 0, 0, 0),
(18, 1, 1290.78, 1598.83, 455.25, 6830, 11, 1929.55, -1776.22, 13.5469, 'Unknown', 7, 0, 0, 0, 5000000, 39755, 65, 35, 1290.43, 1603.15, 455.25, 0, 0, 0, 1938.73, -1773.93, 13.3828, 1291.24, 1603.25, 455.25, 88.8597, 200, 300, 300, 300, 300, 300),
(19, 0, 0, 0, 0, 17149, 0, 1268.33, -1547.47, 13.5606, 'Departement of Motorvehicle', 10, 0, 0, 0, 5000000, 0, 0, 36, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(20, 0, 0, 0, 0, 1605, 0, 1671.55, -2313.43, -2.65855, 'Los Santos Rental', 12, 0, 0, 0, 5000000, 0, 0, 37, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(21, 0, 501.978, -67.9858, 998.758, 11600, 11, 2310.08, -1643.53, 14.827, 'Ganton Bar', 2, 0, 0, 0, 5000000, 0, 95, 49, 496.994, -76.7572, 998.855, 0, 0, 0, 0, 0, 0, 497.305, -77.5615, 998.765, 2.79407, 0, 0, 0, 0, 0, 0),
(22, 61, 772.391, -5.51198, 1000.73, 10720, 5, 2229.5, -1721.69, 13.5653, 'Unknown', 13, 0, 0, 0, 5000000, 0, 0, 54, 758.987, 5.56619, 1000.7, 0, 0, 0, 0, 0, 0, 766.19, 13.6844, 1000.7, 175.342, 0, 0, 0, 0, 0, 0),
(23, 0, 372.404, -133.525, 1001.49, 8234, 5, 2104.91, -1806.39, 13.5547, 'Well Pizza Stack', 1, 0, 0, 0, 5000000, 0, -45, 29, 375.968, -117.812, 1001.57, 0, 0, 0, 0, 0, 0, 375.719, -117.276, 1001.49, 175.382, 0, 0, 0, 0, 0, 0),
(24, 0, 390.625, 173.914, 1008.38, 3950, 3, 1310.09, -1367.84, 13.5412, 'Los Santos Bank', 6, 0, 0, 0, 5000000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(25, 0, 1283.69, 1573.97, 455.25, 6817, 11, 2723.59, -2033.68, 13.5472, 'Unknown', 7, 0, 0, 0, 5000000, 0, 82, 0, 1284.3, 1568.94, 455.25, 0, 0, 0, 0, 0, 0, 1283.48, 1568.74, 455.25, 271.765, 0, 0, 0, 0, 0, 0),
(26, 0, -45.8395, 2.24716, 203.263, 2487, 11, 2424.34, -1997.31, 13.5545, 'Unknown', 7, 0, 0, 0, 5000000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(27, 0, 364.939, -11.8251, 1001.85, 10270, 9, 2419.71, -1509.05, 24, 'Unknown', 1, 0, 0, 0, 5000000, 0, -1, 0, 369.084, -5.20525, 1001.96, 0, 0, 0, 0, 0, 0, 369.11, -4.48834, 1001.85, 177.972, 0, 0, 0, 0, 0, 0),
(28, 0, 0, 0, 0, 13804, 0, 1540.75, -1686.63, 13.5512, 'Pershing Square Rentcars', 12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);

-- --------------------------------------------------------

--
-- Table structure for table `characters`
--

CREATE TABLE `characters` (
  `master_dbid` int(11) NOT NULL,
  `char_dbid` int(11) NOT NULL,
  `char_name` varchar(32) NOT NULL DEFAULT 'None',
  `char_masters` varchar(32) NOT NULL DEFAULT 'None',
  `create_date` varchar(60) NOT NULL DEFAULT 'None',
  `create_ip` varchar(60) NOT NULL DEFAULT 'None',
  `pAdmin` int(4) NOT NULL DEFAULT 0,
  `pLastSkin` int(11) NOT NULL DEFAULT 0,
  `pFacSkin` int(11) NOT NULL DEFAULT 0,
  `pLastPosX` float NOT NULL DEFAULT 1642.02,
  `pLastPosY` float NOT NULL DEFAULT -2334.05,
  `pLastPosZ` float NOT NULL DEFAULT 13.5469,
  `pLastInterior` int(11) NOT NULL DEFAULT 0,
  `pLastWorld` int(11) NOT NULL DEFAULT 0,
  `pLevel` int(11) NOT NULL DEFAULT 1,
  `pWantedLevel` int(11) NOT NULL DEFAULT 0,
  `pEXP` int(11) NOT NULL DEFAULT 0,
  `pAge` int(11) NOT NULL DEFAULT 18,
  `pHeight` int(11) NOT NULL DEFAULT 0,
  `pEthnicity` varchar(32) NOT NULL DEFAULT 'Invalid',
  `pHair` varchar(32) NOT NULL DEFAULT 'Invalid',
  `pEyes` varchar(32) NOT NULL DEFAULT 'Invalid',
  `pDescription` varchar(32) NOT NULL DEFAULT 'Invalid',
  `pGender` int(11) NOT NULL DEFAULT 0,
  `pStory` varchar(90) NOT NULL DEFAULT 'Nothing',
  `pStoryTwo` varchar(90) NOT NULL DEFAULT 'Nothing',
  `pMoney` int(11) NOT NULL DEFAULT 10000,
  `pBank` int(11) NOT NULL DEFAULT 5000,
  `pPaycheck` int(11) NOT NULL DEFAULT 0,
  `pPhone` int(11) NOT NULL DEFAULT 0,
  `pLastOnline` varchar(90) NOT NULL DEFAULT 'None',
  `pLastOnlineTime` int(11) NOT NULL DEFAULT 0,
  `pAdminjailed` tinyint(1) NOT NULL DEFAULT 0,
  `pAdminJailTime` int(11) NOT NULL DEFAULT 0,
  `pOfflinejailed` tinyint(1) NOT NULL DEFAULT 0,
  `pOfflinejailedReason` varchar(128) NOT NULL DEFAULT 'None',
  `pFaction` int(11) NOT NULL DEFAULT 0,
  `pFactionRank` int(11) NOT NULL DEFAULT 0,
  `pFactionSubsets` int(11) NOT NULL DEFAULT 0,
  `pOwnedVehicles1` int(11) NOT NULL DEFAULT 0,
  `pOwnedVehicles2` int(11) NOT NULL DEFAULT 0,
  `pOwnedVehicles3` int(11) NOT NULL DEFAULT 0,
  `pOwnedVehicles4` int(11) NOT NULL DEFAULT 0,
  `pOwnedVehicles5` int(11) NOT NULL DEFAULT 0,
  `pVehicleSpawned` tinyint(1) NOT NULL DEFAULT 0,
  `pVehicleSpawnedID` int(11) NOT NULL DEFAULT 0,
  `pTimeplayed` int(11) NOT NULL DEFAULT 0,
  `pMaskID` int(11) NOT NULL DEFAULT 0,
  `pMaskIDEx` int(11) NOT NULL DEFAULT 0,
  `pInProperty` int(11) NOT NULL DEFAULT 0,
  `pInBusiness` int(11) NOT NULL DEFAULT 0,
  `pInEntrance` int(11) NOT NULL DEFAULT 0,
  `pRadio1` int(11) NOT NULL DEFAULT 0,
  `pRadio2` int(11) NOT NULL DEFAULT 0,
  `pMainSlot` int(11) NOT NULL DEFAULT 1,
  `pSpawnPoint` int(11) NOT NULL DEFAULT 0,
  `pSpawnPointHouse` int(11) NOT NULL DEFAULT 0,
  `pWeaponsLicense` int(11) NOT NULL DEFAULT 0,
  `pDriversLicense` int(11) NOT NULL DEFAULT 0,
  `pTruckerLicense` int(11) NOT NULL DEFAULT 0,
  `pActiveListings` int(11) NOT NULL DEFAULT 0,
  `pPrisonTimes` int(11) NOT NULL DEFAULT 0,
  `pPrison` tinyint(1) NOT NULL DEFAULT 0,
  `pInFaction` int(11) NOT NULL DEFAULT 0,
  `pRobberyCooldown` int(11) NOT NULL DEFAULT 0,
  `pFightstyle` int(11) NOT NULL DEFAULT 4,
  `pHasAoe` int(11) NOT NULL DEFAULT 0,
  `pHasInjured` tinyint(1) NOT NULL DEFAULT 0,
  `pHasDeath` tinyint(1) NOT NULL DEFAULT 0,
  `pHungry` float NOT NULL DEFAULT 100,
  `pThirsty` float NOT NULL DEFAULT 100,
  `pHealth` float NOT NULL DEFAULT 100,
  `pMaxHealth` float NOT NULL DEFAULT 100,
  `pArmor` float NOT NULL DEFAULT 0,
  `pToggleAdmin` tinyint(1) NOT NULL DEFAULT 0,
  `pToggleHUD` tinyint(1) NOT NULL DEFAULT 0,
  `pToggleJoined` tinyint(1) NOT NULL DEFAULT 0,
  `pBodyPart1` int(11) NOT NULL DEFAULT 100,
  `pBodyPart2` int(11) NOT NULL DEFAULT 100,
  `pBodyPart3` int(11) NOT NULL DEFAULT 100,
  `pBodyPart4` int(11) NOT NULL DEFAULT 100,
  `pBodyPart5` int(11) NOT NULL DEFAULT 100,
  `pBodyPart6` int(11) NOT NULL DEFAULT 100,
  `pBodyPart7` int(11) NOT NULL DEFAULT 100,
  `pBodyPart8` int(11) NOT NULL DEFAULT 100,
  `pWound1` int(11) NOT NULL DEFAULT 0,
  `pWound2` int(11) NOT NULL DEFAULT 0,
  `pWound3` int(11) NOT NULL DEFAULT 0,
  `pWound4` int(11) NOT NULL DEFAULT 0,
  `pWound5` int(11) NOT NULL DEFAULT 0,
  `pWound6` int(11) NOT NULL DEFAULT 0,
  `pWound7` int(11) NOT NULL DEFAULT 0,
  `pWound8` int(11) NOT NULL DEFAULT 0,
  `pJobs` int(11) NOT NULL DEFAULT 0,
  `pJobsCD` int(11) NOT NULL DEFAULT 0,
  `pSweeperCD` int(11) NOT NULL DEFAULT 0,
  `pGarbageCD` int(11) NOT NULL DEFAULT 0,
  `pBusdriverCD` int(11) NOT NULL DEFAULT 0,
  `pDockworkerCD` int(11) NOT NULL DEFAULT 0,
  `pTutorial` int(11) NOT NULL DEFAULT 0
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COLLATE=latin1_swedish_ci;

--
-- Dumping data for table `characters`
--

INSERT INTO `characters` (`master_dbid`, `char_dbid`, `char_name`, `char_masters`, `create_date`, `create_ip`, `pAdmin`, `pLastSkin`, `pFacSkin`, `pLastPosX`, `pLastPosY`, `pLastPosZ`, `pLastInterior`, `pLastWorld`, `pLevel`, `pWantedLevel`, `pEXP`, `pAge`, `pHeight`, `pEthnicity`, `pHair`, `pEyes`, `pDescription`, `pGender`, `pStory`, `pStoryTwo`, `pMoney`, `pBank`, `pPaycheck`, `pPhone`, `pLastOnline`, `pLastOnlineTime`, `pAdminjailed`, `pAdminJailTime`, `pOfflinejailed`, `pOfflinejailedReason`, `pFaction`, `pFactionRank`, `pFactionSubsets`, `pOwnedVehicles1`, `pOwnedVehicles2`, `pOwnedVehicles3`, `pOwnedVehicles4`, `pOwnedVehicles5`, `pVehicleSpawned`, `pVehicleSpawnedID`, `pTimeplayed`, `pMaskID`, `pMaskIDEx`, `pInProperty`, `pInBusiness`, `pInEntrance`, `pRadio1`, `pRadio2`, `pMainSlot`, `pSpawnPoint`, `pSpawnPointHouse`, `pWeaponsLicense`, `pDriversLicense`, `pTruckerLicense`, `pActiveListings`, `pPrisonTimes`, `pPrison`, `pInFaction`, `pRobberyCooldown`, `pFightstyle`, `pHasAoe`, `pHasInjured`, `pHasDeath`, `pHungry`, `pThirsty`, `pHealth`, `pMaxHealth`, `pArmor`, `pToggleAdmin`, `pToggleHUD`, `pToggleJoined`, `pBodyPart1`, `pBodyPart2`, `pBodyPart3`, `pBodyPart4`, `pBodyPart5`, `pBodyPart6`, `pBodyPart7`, `pBodyPart8`, `pWound1`, `pWound2`, `pWound3`, `pWound4`, `pWound5`, `pWound6`, `pWound7`, `pWound8`, `pJobs`, `pJobsCD`, `pSweeperCD`, `pGarbageCD`, `pBusdriverCD`, `pDockworkerCD`, `pTutorial`) VALUES
(18, 1, 'Ethan_Pattersons', 'Radeetz', 'June 2, 2024 11:49:50', '127.0.0.1', 4, 144, 20263, 1778.03, -1663.49, 14.4356, 0, 0, 6, 1, 2, 25, 0, 'Los Santos', 'Invalid', 'Invalid', 'Invalid', 1, '', '', 75971, 22800, 0, 96205, 'December 29, 2024 19:36:26', 0, 0, 0, 0, 'a', 1, 4, 2, 96, 101, 109, 115, 0, 0, 12, 3, 338452, 58, 0, 0, 1, 0, 0, 1, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 15, 1, 0, 0, 37.85, 23.36, 100, 100, 0, 0, 0, 0, 100, 100, 100, 100, 100, 100, 100, 0, 0, 0, 0, 0, 0, 0, 0, 100, 1, 0, 0, 0, 0, 0, 1),
(121, 60, 'Giovanna_Rodriguez', 'notubidev', 'December 6, 2024 13:29:14', '180.254.174.40', 0, 303, 20267, 1567.29, -1695.18, 5.89062, 0, 0, 1, 0, 1, 25, 190, 'Latino', 'Blonde', 'Black', 'Invalid', 1, 'Nothing', 'Nothing', 150, 250, 4000, 94768, 'December 23, 2024 22:18:22', 30, 0, 0, 0, 'None', 1, 4, 0, 0, 0, 0, 0, 0, 0, 65535, 0, 394574, 0, 0, 0, 1, 0, 0, 1, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 1, 0, 0, 41.38, 40.66, 100, 100, 100, 0, 0, 0, 100, 100, 100, 100, 100, 100, 100, 100, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1),
(131, 61, 'Charles_Morgan', 'Charlie', 'December 6, 2024 16:59:44', '103.76.91.60', 0, 20004, 0, 807.246, -595.794, 17.2059, 0, 0, 9, 0, 2, 20, 190, 'White', 'Brown', 'Blue', 'Invalid', 1, 'Nothing', 'Nothing', 103150, 1550253, 0, 95845, 'January 2, 2025 09:56:54', 14, 0, 0, 0, 'None', 0, 0, 0, 97, 104, 0, 0, 0, 0, 5, 5, 333293, 0, 0, 0, 0, 0, 0, 1, 10, 0, 0, 1, 0, 0, 0, 0, 0, 0, 4, 1, 0, 0, 71.28, 90.36, 95, 100, 200, 0, 0, 0, 95, 100, 100, 100, 100, 1, 100, 100, 1, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 1),
(127, 62, 'Quincy_Brentwood', 'genitals', 'December 6, 2024 17:50:27', '180.252.174.4', 0, 20007, 0, 1667.16, -1537.73, 13.5469, 0, 0, 1, 0, 1, 21, 190, 'Black', 'Black', 'Brown', 'Invalid', 1, 'Nothing', 'Nothing', 10250, 250, 0, 98202, 'December 10, 2024 20:40:40', 2, 0, 0, 0, 'None', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 370745, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 1, 0, 0, 25.27, 25.56, 100, 100, 0, 0, 0, 0, 100, 100, 100, 100, 100, 100, 100, 100, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1),
(135, 63, 'Kemal_Champbell', 'whackt', 'December 7, 2024 13:37:31', '103.138.49.7', 0, 14, 0, 1340.49, 895.953, 131.935, 0, 138, 1, 0, 0, 18, 186, 'Black', 'Bald', 'Black', 'Invalid', 1, 'Nothing', 'Nothing', 35000, 5000, 0, 97735, 'December 7, 2024 13:46:22', 5, 0, 0, 0, 'None', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 223238, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 1, 1, 0, 95.43, 95.51, 0, 100, 0, 0, 0, 0, 100, 100, 100, 100, 100, 100, 100, 100, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1),
(113, 64, 'Markael_Thompson', 'dookie', 'December 7, 2024 13:41:46', '110.136.222.94', 0, 297, 0, 2321.73, -1666.62, 13.9737, 0, 0, 1, 0, 0, 17, 189, 'Black', 'Black', 'Black', 'Invalid', 1, 'Nothing', 'Nothing', 35000, 5000, 0, 97228, 'December 8, 2024 20:57:47', 0, 0, 0, 0, 'None', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 200751, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 1, 0, 0, 92.37, 89.2, 100, 100, 0, 0, 0, 0, 100, 100, 100, 100, 100, 100, 100, 100, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1),
(125, 65, 'Ismael_Salazar', 'mikelo', 'December 7, 2024 13:45:21', '114.10.101.55', 0, 108, 0, 817.254, -601.101, 16.3359, 0, 0, 1, 0, 1, 19, 183, 'Latino', 'Black', 'Black', 'Invalid', 1, 'Nothing', 'Nothing', 701090, 5000, 0, 98206, 'January 2, 2025 10:05:56', 4, 0, 0, 0, 'None', 0, 0, 0, 118, 0, 0, 0, 0, 0, 0, 1, 352697, 0, 0, 0, 0, 0, 0, 1, 10, 0, 0, 1, 0, 0, 0, 0, 0, 0, 4, 1, 0, 0, 68.97, 93.81, 100, 100, 0, 0, 0, 0, 100, 100, 100, 100, 100, 100, 100, 100, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1),
(138, 66, 'Oedin_Djambroed', 'JhonAndreas', 'December 7, 2024 13:46:36', '180.244.138.123', 0, 14, 0, 1838.85, -1557.01, 13.3754, 0, 0, 1, 0, 0, 23, 186, 'Latino', 'Black', 'Brown', 'Invalid', 1, 'Nothing', 'Nothing', 44990, 5000, 0, 94850, 'December 8, 2024 21:02:23', 1, 0, 0, 0, 'None', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 280462, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 1, 0, 0, 87.55, 94.24, 100, 100, 0, 0, 0, 0, 100, 100, 100, 100, 100, 100, 100, 100, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1),
(130, 69, 'Rafael_Montana', 'starz', 'December 7, 2024 13:52:46', '103.175.229.201', 0, 20005, 0, 1693.03, -1523.38, 13.5469, 0, 0, 1, 0, 0, 20, 186, 'White', 'Brown', 'Black', 'Invalid', 1, 'Nothing', 'Nothing', 34990, 5000, 0, 97688, 'December 7, 2024 19:15:02', 0, 0, 0, 0, 'None', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 283419, 0, 0, 9, 3, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 1, 0, 0, 71.79, 80.6, 96, 100, 0, 0, 0, 0, 86, 100, 100, 100, 100, 100, 100, 100, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1),
(120, 70, 'Mara_DaylonT', 'DaylonT', 'December 7, 2024 13:53:39', '114.10.156.162', 0, 269, 0, 2131.56, -1147.37, 24.4856, 0, 0, 1, 0, 1, 20, 186, 'White', 'Brown', 'Black', 'Invalid', 1, 'Nothing', 'Nothing', 30000, 5000, 0, 97632, 'December 8, 2024 08:44:30', 20, 0, 0, 0, 'None', 0, 0, 0, 99, 0, 0, 0, 0, 1, 45, 0, 237115, 0, 0, 0, 2, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 4, 1, 0, 0, 69.91, 76.24, 100, 100, 0, 0, 0, 0, 0, 100, 100, 100, 100, 1, 100, 100, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1),
(116, 71, 'Jamyron_Perkins', 'Bavallgo', 'December 7, 2024 14:04:20', '180.253.191.99', 0, 86, 0, 2303.18, -1646.74, 14.5952, 0, 0, 1, 0, 1, 18, 178, 'Black', 'Black', 'Blue', 'Invalid', 1, 'Nothing', 'Nothing', 231460, 5000, 0, 98594, 'December 28, 2024 06:29:24', 4, 0, 0, 0, 'None', 0, 0, 0, 0, 0, 0, 0, 0, 0, 65535, 0, 211957, 0, 0, 0, 0, 0, 0, 1, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 1, 0, 0, 93.72, 91.87, 100, 100, 20, 0, 0, 0, 100, 100, 100, 100, 100, 100, 100, 100, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1),
(120, 72, 'Jahared_Haswel', 'DaylonT', 'December 7, 2024 14:05:16', '114.10.156.162', 0, 20004, 0, 0, 0, 0, 0, 0, 1, 0, 0, 17, 175, 'Black', 'Bald', 'Black', 'Invalid', 1, 'Nothing', 'Nothing', 10000, 5000, 0, 96986, 'None', 0, 0, 0, 0, 'None', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 100, 100, 100, 100, 0, 0, 0, 0, 100, 100, 100, 100, 100, 100, 100, 100, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(138, 73, 'Oedjang_Djambroed', 'JhonAndreas', 'December 7, 2024 14:07:25', '180.244.138.123', 0, 236, 0, 2717.24, -1300.57, 53.9833, 0, 0, 1, 0, 0, 23, 186, 'Latino', 'Black', 'Black', 'Invalid', 1, 'Nothing', 'Nothing', 10000, 5000, 0, 97940, 'December 7, 2024 14:08:17', 1, 0, 0, 0, 'None', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 326835, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 1, 0, 0, 99.66, 99.89, 100, 100, 0, 0, 0, 0, 91, 100, 100, 100, 100, 1, 100, 100, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1),
(140, 74, 'Tasiah_Knott', 'Cockup', 'December 7, 2024 14:07:50', '114.10.156.45', 0, 19, 0, 1715.73, -1586.53, 13.5453, 0, 0, 1, 0, 0, 24, 180, 'Black', 'Black', 'Black', 'Invalid', 1, 'Nothing', 'Nothing', 16900, 5000, 0, 94794, 'December 30, 2024 16:14:00', 6, 0, 0, 0, 'None', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 264757, 0, 0, 0, 0, 0, 0, 1, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 1, 0, 0, 83.58, 88.6, 100, 100, 0, 0, 0, 0, 95, 100, 100, 100, 100, 1, 100, 100, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1),
(140, 75, 'Tasiah_Knott', 'Cockup', 'December 7, 2024 14:08:02', '114.10.156.45', 0, 142, 0, 0, 0, 0, 0, 0, 1, 0, 0, 24, 180, 'Black', 'Black', 'Black', 'Invalid', 1, 'Nothing', 'Nothing', 10000, 5000, 0, 97106, 'None', 0, 0, 0, 0, 'None', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 100, 100, 100, 100, 0, 0, 0, 0, 100, 100, 100, 100, 100, 100, 100, 100, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(139, 76, 'Jabarem_Hasheel', 'Martabak', 'December 7, 2024 14:09:31', '180.244.167.28', 0, 8, 0, 2218.84, -1306.02, 23.9844, 0, 0, 1, 0, 0, 18, 178, 'Black', 'Black', 'Black', 'Invalid', 1, 'Nothing', 'Nothing', 10000, 5000, 0, 95929, 'December 8, 2024 22:52:37', 3, 0, 0, 0, 'None', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 394248, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 1, 0, 1, 97.9, 99.08, 100, 100, 0, 0, 0, 0, 100, 100, 100, 100, 100, 100, 100, 100, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1),
(133, 77, 'Riyoo_Layee', 'ruztol', 'December 7, 2024 14:12:41', '112.215.244.136', 0, 292, 0, 1928.58, -1774.7, 13.5469, 11, 18, 1, 0, 0, 19, 186, 'Latino', 'Bald', 'Gray', 'Invalid', 1, 'Nothing', 'Nothing', 45000, 5000, 0, 96858, 'December 12, 2024 07:04:59', 0, 0, 0, 0, 'None', 0, 0, 0, 0, 0, 0, 0, 0, 0, 65535, 0, 258179, 0, 0, 4, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 1, 0, 0, 78.39, 77.29, 100, 100, 0, 0, 0, 0, 100, 100, 100, 100, 100, 100, 100, 100, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1),
(141, 78, 'Brayn_Conwell', 'randz', 'December 7, 2024 14:15:54', '180.249.201.150', 0, 300, 302, 1034.48, -1028.01, 32.1016, 0, 0, 4, 0, 1, 21, 180, 'Black', 'Black', 'Black', 'Invalid', 1, 'Nothing', 'Nothing', 4365540, 1164000, 3000, 100115, 'December 31, 2024 13:35:24', 0, 0, 0, 0, 'None', 1, 4, 0, 106, 103, 0, 102, 0, 0, 9, 13, 227390, 0, 0, 0, 1, 1, 0, 1, 10, 0, 0, 1, 1, 0, 0, 0, 0, 0, 4, 1, 0, 0, 69.11, 91.23, 100, 100, 0, 0, 0, 0, 100, 100, 100, 100, 100, 100, 100, 100, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 1),
(60, 79, 'Bryan_McCardle', 'Blixkyyy', 'December 7, 2024 15:05:15', '103.147.9.108', 0, 144, 0, 0, 0, 0, 0, 0, 1, 0, 0, 19, 186, 'Black', 'Brown', 'Black', 'Invalid', 1, 'Nothing', 'Nothing', 10000, 5000, 0, 100403, 'December 7, 2024 15:06:31', 1, 0, 0, 0, 'None', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 293410, 0, 0, 0, 0, 0, 0, 1, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 1, 0, 0, 98.6, 98.89, 100, 100, 0, 0, 0, 0, 100, 100, 100, 100, 100, 100, 100, 100, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1),
(143, 80, 'Lawliieet_Jarvis', 'stranger', 'December 7, 2024 16:03:44', '114.10.12.220', 0, 270, 0, 887.417, -1223.25, 16.9659, 0, 0, 1, 0, 1, 23, 160, 'White', 'Bald', 'Black', 'Invalid', 1, 'Nothing', 'Nothing', 173260, 5000, 0, 96684, 'January 1, 2025 14:30:25', 2, 0, 0, 0, 'None', 0, 0, 0, 111, 0, 0, 0, 0, 0, 0, 1, 239011, 0, 0, 0, 0, 1, 0, 1, 10, 0, 0, 1, 0, 0, 0, 0, 0, 0, 4, 1, 0, 0, 55.7001, 19.5803, 100, 100, 0, 0, 0, 0, 100, 100, 100, 100, 100, 100, 100, 100, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1),
(115, 81, 'Bruno_Herisson', 'imo_string', 'December 7, 2024 16:09:34', '36.83.0.105', 0, 114, 0, 2207.38, -1481.81, 23.9844, 0, 0, 1, 0, 0, 22, 182, 'Black', 'Brown', 'Hazel', 'Invalid', 1, 'Nothing', 'Nothing', 45000, 5000, 0, 97211, 'December 20, 2024 21:27:55', 2, 0, 0, 0, 'None', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 254005, 0, 0, 0, 0, 0, 0, 1, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 1, 0, 0, 91.68, 94.31, 100, 100, 0, 0, 0, 0, 100, 100, 100, 100, 100, 100, 100, 100, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1),
(128, 82, 'Angelina_Christy', 'Christy', 'December 7, 2024 16:09:49', '103.108.31.84', 0, 13, 0, 2317.3, -1660.54, 14.0516, 0, 0, 1, 0, 0, 20, 180, 'White', 'Brown', 'Brown', 'Invalid', 2, 'Nothing', 'Nothing', 10000, 5000, 0, 97270, 'December 7, 2024 19:19:19', 4, 0, 0, 0, 'None', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 296852, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 1, 0, 0, 97.95, 97.01, 100, 100, 0, 0, 0, 0, 95, 100, 100, 100, 100, 1, 100, 100, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1),
(128, 83, 'Angelina_Christy', 'Christy', 'December 7, 2024 16:09:56', '103.108.31.84', 0, 13, 0, 0, 0, 0, 0, 0, 1, 0, 0, 20, 180, 'White', 'Brown', 'Brown', 'Invalid', 2, 'Nothing', 'Nothing', 10000, 5000, 0, 95016, 'None', 0, 0, 0, 0, 'None', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 100, 100, 100, 100, 0, 0, 0, 0, 100, 100, 100, 100, 100, 100, 100, 100, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(122, 84, 'Tavari_Ware', 'Droppes', 'December 7, 2024 16:12:34', '180.253.188.1', 0, 20022, 0, 1754.63, -1674.76, 13.5494, 0, 0, 1, 0, 0, 18, 188, 'Black', 'Black', 'Amber', 'Invalid', 1, 'Nothing', 'Nothing', 35000, 5000, 0, 100388, 'December 29, 2024 14:29:11', 32, 0, 0, 0, 'None', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 310599, 0, 0, 0, 1, 0, 0, 1, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 1, 0, 0, 82.26, 99.1, 87, 100, 0, 0, 0, 0, 80, 100, 100, 100, 100, 95, 100, 100, 1, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 1),
(142, 85, 'Omar_Epps', 'Joozxc', 'December 7, 2024 16:49:31', '36.85.216.24', 0, 20001, 0, 0, 0, 0, 0, 0, 1, 0, 0, 18, 186, 'Black', 'Black', 'Black', 'Invalid', 1, 'Nothing', 'Nothing', 20000, 5000, 0, 98416, 'December 7, 2024 19:17:18', 5, 0, 0, 0, 'None', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 316771, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 1, 0, 0, 71.83, 70.99, 0, 100, 0, 0, 0, 0, 0, 100, 100, 100, 100, 1, 0, 100, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1),
(146, 86, 'Juanito_Bless', 'ghaisendra', 'December 7, 2024 16:51:15', '104.28.162.12', 0, 108, 0, 1716.54, -1604.19, 13.5469, 0, 0, 1, 0, 1, 18, 180, 'Latino', 'Black', 'Black', 'Invalid', 1, 'Nothing', 'Nothing', 18980, 5000, 0, 98568, 'December 14, 2024 19:02:21', 9, 0, 0, 0, 'None', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 354714, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 1, 0, 0, 73.93, 83.79, 45, 100, 0, 0, 0, 0, 0, 100, 100, 100, 100, 1, 100, 100, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1),
(148, 87, 'Marshall_Pierra', 'Xenzy', 'December 7, 2024 17:21:28', '104.28.159.172', 0, 154, 0, 0, 0, 0, 0, 0, 1, 0, 0, 18, 180, 'White', 'Bald', 'Black', 'Invalid', 1, 'Nothing', 'Nothing', 66100, 5000, 0, 95898, 'December 7, 2024 17:31:54', 1, 0, 0, 0, 'None', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 347090, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 1, 0, 0, 54.9797, 25.11, 0, 100, 0, 0, 0, 0, 100, 100, 100, 100, 100, 100, 100, 100, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 11, 0, 1),
(148, 88, 'Marshall_Pierra', 'Xenzy', 'December 7, 2024 17:21:41', '104.28.159.172', 0, 154, 0, 0, 0, 0, 0, 0, 1, 0, 0, 18, 180, 'White', 'Bald', 'Black', 'Invalid', 1, 'Nothing', 'Nothing', 10000, 5000, 0, 97955, 'None', 0, 0, 0, 0, 'None', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 100, 100, 100, 100, 0, 0, 0, 0, 100, 100, 100, 100, 100, 100, 100, 100, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(114, 90, 'Joseph_Vier', 'ghivin', 'December 7, 2024 18:00:01', '103.163.36.86', 0, 106, 300, 856.888, -1386.96, 13.7326, 0, 0, 2, 0, 1, 21, 183, 'Black', 'Black', 'Black', 'Invalid', 1, 'Nothing', 'Nothing', 26460, 5000, 0, 100137, 'January 1, 2025 14:31:30', 4, 0, 0, 0, 'None', 1, 1, 0, 105, 0, 0, 0, 0, 0, 5, 6, 245641, 0, 0, 0, 0, 0, 0, 1, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 1, 0, 0, 61.13, 94.74, 100, 100, 0, 0, 0, 0, 100, 100, 100, 100, 100, 100, 100, 100, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1),
(150, 91, 'Betrayal_Burnns', 'sweaat', 'December 7, 2024 18:10:31', '114.198.244.11', 0, 154, 0, 1994.03, -1542.05, 12.2873, 0, 0, 1, 0, 0, 18, 170, 'Latino', 'Black', 'Black', 'Invalid', 1, 'Nothing', 'Nothing', 19900, 5000, 0, 97165, 'December 7, 2024 18:24:54', 1, 0, 0, 0, 'None', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 276551, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 1, 0, 0, 87.0899, 80.6, 100, 100, 0, 0, 0, 0, 89, 100, 100, 100, 100, 1, 100, 100, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9, 0, 1),
(123, 92, 'Lyn_Seraphine', 'graceee', 'December 7, 2024 18:11:05', '114.122.21.101', 0, 193, 0, 1129.37, -1425.7, 15.7969, 0, 0, 1, 0, 1, 20, 160, 'Asian', 'Black', 'Black', 'Invalid', 2, 'Nothing', 'Nothing', 41300, 5000, 0, 98182, 'December 26, 2024 19:19:50', 2, 0, 0, 0, 'None', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 317366, 0, 0, 0, 0, 0, 0, 1, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 1, 0, 0, 78.95, 65.88, 100, 100, 0, 0, 0, 0, 100, 100, 100, 100, 100, 100, 100, 100, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1),
(151, 93, 'Liu_Cheng', 'LaputaNZ', 'December 7, 2024 18:41:21', '182.3.47.228', 0, 62, 0, 1693.86, -1490.94, 13.5469, 0, 0, 1, 0, 0, 23, 186, 'Asian', 'Black', 'Black', 'Invalid', 1, 'Nothing', 'Nothing', 10000, 5000, 0, 97783, 'December 7, 2024 18:48:02', 1, 0, 0, 0, 'None', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 245600, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 1, 0, 0, 99.42, 99.24, 100, 100, 0, 0, 0, 0, 100, 100, 100, 100, 100, 100, 100, 100, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1),
(153, 94, 'Jahmes_Wiggins', 'Sigma', 'December 7, 2024 21:38:04', '180.249.201.150', 0, 36, 0, 1809.03, -1577.37, 13.4973, 0, 0, 1, 0, 1, 17, 186, 'Black', 'Black', 'Black', 'Invalid', 1, 'Nothing', 'Nothing', 25000, 5000, 0, 95718, 'December 26, 2024 20:18:31', 9, 0, 0, 0, 'None', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 289781, 0, 0, 0, 1, 0, 0, 1, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 1, 0, 0, 92.61, 92.53, 98, 100, 0, 0, 0, 0, 91, 100, 100, 100, 100, 100, 100, 100, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1),
(155, 95, 'Quintrell_Adarrion', 'anocc', 'December 7, 2024 22:36:10', '180.242.143.64', 0, 20007, 0, 2315.91, -1653.4, 14.2769, 0, 0, 1, 0, 0, 20, 186, 'Black', 'Black', 'Black', 'Invalid', 1, 'Nothing', 'Nothing', 17000, 5000, 0, 100162, 'December 8, 2024 09:30:57', 3, 0, 0, 0, 'None', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 337117, 0, 0, 0, 0, 0, 0, 1, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 1, 0, 0, 82.09, 81.43, 97, 100, 0, 0, 0, 0, 67, 100, 100, 100, 100, 1, 100, 100, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1),
(155, 96, 'Quintrell_Adarrion', 'anocc', 'December 7, 2024 22:36:18', '180.242.143.64', 0, 36, 0, 0, 0, 0, 0, 0, 1, 0, 0, 20, 186, 'Black', 'Black', 'Black', 'Invalid', 1, 'Nothing', 'Nothing', 10000, 5000, 0, 94610, 'None', 0, 0, 0, 0, 'None', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 100, 100, 100, 100, 0, 0, 0, 0, 100, 100, 100, 100, 100, 100, 100, 100, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(155, 97, 'Charllie_Onaille', 'anocc', 'December 7, 2024 22:52:02', '180.242.143.64', 0, 68, 0, 332.923, -117.85, 1.41626, 0, 0, 1, 0, 0, 20, 186, 'White', 'Bald', 'Black', 'Invalid', 1, 'Nothing', 'Nothing', 10000, 5000, 0, 98386, 'December 7, 2024 22:54:33', 1, 0, 0, 0, 'None', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 244024, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 1, 0, 0, 99.61, 99.89, 100, 100, 0, 0, 0, 0, 86, 100, 100, 100, 100, 1, 100, 100, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1),
(155, 98, 'Ornelle_Adarrion', 'anocc', 'December 7, 2024 22:58:40', '180.242.143.64', 0, 20007, 0, 0, 0, 0, 0, 0, 1, 0, 1, 20, 186, 'White', 'Bald', 'Black', 'Invalid', 1, 'Nothing', 'Nothing', 0, 5000, 0, 99985, 'December 8, 2024 09:01:30', 1, 0, 0, 0, 'None', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 332202, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 1, 0, 0, 74.14, 74.98, 0, 100, 0, 0, 0, 0, 77, 100, 100, 100, 100, 1, 100, 100, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1),
(144, 99, 'Matias_Basilio', 'chooo', 'December 8, 2024 00:58:04', '114.122.198.105', 0, 36, 0, 1208.59, -1327.38, 13.3984, 0, 0, 1, 0, 0, 25, 186, 'Latino', 'Black', 'Black', 'Invalid', 1, 'Nothing', 'Nothing', 10000, 5000, 0, 96973, 'December 8, 2024 08:10:30', 1, 0, 0, 0, 'None', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 392351, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 1, 0, 0, 96.49, 97.66, 100, 100, 0, 0, 0, 0, 88, 100, 100, 100, 100, 1, 100, 100, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1),
(157, 100, 'Lamar_Naheem', 'podka', 'December 8, 2024 08:47:49', '114.10.101.65', 0, 158, 0, 2308.09, -1652.84, 14.4824, 11, 0, 1, 0, 0, 20, 185, 'Black', 'Black', 'Black', 'Invalid', 1, 'Nothing', 'Nothing', 30000, 5000, 0, 98269, 'December 8, 2024 09:08:28', 0, 0, 0, 0, 'None', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 292348, 0, 0, 0, 0, 0, 0, 1, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 1, 0, 0, 95.03, 95.83, 100, 100, 0, 0, 0, 0, 77, 100, 100, 100, 100, 1, 100, 100, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1),
(127, 101, 'Marcel_Randles', 'genitals', 'December 8, 2024 09:22:23', '180.252.174.4', 0, 20005, 0, 1978.11, -1447.23, 13.5639, 0, 0, 1, 0, 0, 21, 186, 'White', 'Black', 'Black', 'Invalid', 1, 'Nothing', 'Nothing', 10000, 5000, 0, 97454, 'December 8, 2024 09:27:00', 2, 0, 0, 0, 'None', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 325893, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 1, 0, 0, 98.56, 97.83, 100, 100, 0, 0, 0, 0, 94, 100, 100, 100, 100, 1, 100, 100, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1),
(18, 102, 'Ethan_Patterson', 'Radeetz', 'December 8, 2024 10:44:29', '103.147.9.108', 0, 20011, 0, 2291.38, -1516.34, 26.875, 0, 0, 1, 0, 0, 19, 186, 'Black', 'Black', 'Brown', 'Invalid', 1, 'Nothing', 'Nothing', 3000, 5000, 0, 96019, 'December 8, 2024 12:31:48', 30, 0, 0, 0, 'None', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 374611, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 1, 0, 0, 85.62, 86.25, 100, 100, 0, 0, 0, 0, 94, 100, 100, 100, 100, 1, 100, 100, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1),
(121, 103, 'Test_Character', 'notubidev', 'December 8, 2024 13:24:01', '180.254.174.40', 0, 121, 0, 1519.41, -1686.43, 13.5469, 0, 0, 1, 0, 0, 25, 186, 'White', 'Bald', 'Black', 'Invalid', 1, 'Nothing', 'Nothing', -80000, 95000, 0, 95577, 'December 11, 2024 09:40:20', 19, 0, 0, 0, 'None', 0, 0, 0, 0, 0, 0, 0, 0, 0, 65535, 0, 390261, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 1, 0, 0, 85.98, 82.64, 100, 100, 0, 0, 0, 0, 89, 100, 100, 100, 100, 100, 100, 100, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1),
(124, 104, 'Jayden_Greenwood', 'Brugiel', 'December 8, 2024 16:59:17', '140.213.161.120', 0, 35, 0, 2450.09, -1364.28, 23.9254, 0, 0, 1, 0, 0, 25, 186, 'White', 'Bald', 'Black', 'Invalid', 1, 'Nothing', 'Nothing', 10000, 5000, 0, 100562, 'December 8, 2024 18:28:03', 9, 0, 0, 0, 'None', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 373434, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 1, 0, 0, 95.9, 94.53, 100, 100, 0, 0, 0, 0, 100, 100, 100, 100, 100, 100, 100, 100, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1),
(169, 105, 'Karver_Alston', 'glxko', 'December 8, 2024 19:13:41', '114.79.3.155', 0, 20007, 0, 2257.57, -1307.88, 23.9844, 0, 0, 1, 0, 0, 18, 186, 'Black', 'Black', 'Black', 'Invalid', 1, 'Nothing', 'Nothing', 5000, 5000, 0, 95359, 'December 9, 2024 06:29:46', 0, 0, 0, 0, 'None', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 212779, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 1, 0, 0, 91.38, 90.33, 100, 100, 0, 0, 0, 0, 100, 100, 100, 100, 100, 100, 100, 100, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1),
(161, 106, 'Xavier_Hompton', 'malayboyswag', 'December 8, 2024 19:24:41', '103.189.201.189', 0, 20, 0, 1539.74, -1657.22, 5.89699, 0, 0, 1, 0, 0, 18, 186, 'Black', 'Black', 'Black', 'Invalid', 1, 'Nothing', 'Nothing', 5000, 5000, 0, 100825, 'December 8, 2024 23:17:52', 1, 0, 0, 0, 'None', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 244147, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 1, 0, 0, 95.98, 96.59, 100, 100, 0, 0, 0, 0, 100, 100, 100, 100, 100, 100, 100, 100, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1),
(133, 107, 'Dario_Daren', 'ruztol', 'December 8, 2024 21:08:50', '140.213.57.60', 0, 57, 0, 1796.87, -1617.9, 13.4516, 0, 0, 1, 0, 0, 18, 186, 'Black', 'Black', 'Hazel', 'Invalid', 1, 'Nothing', 'Nothing', 20000, 5000, 0, 100526, 'December 13, 2024 16:11:34', 0, 0, 0, 0, 'None', 0, 0, 0, 0, 0, 0, 0, 0, 0, 65535, 0, 264779, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 1, 0, 0, 97.62, 97.31, 100, 100, 0, 0, 0, 0, 100, 100, 100, 100, 100, 100, 100, 100, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1),
(175, 108, 'Kyle_Pash', 'antoslayer', 'December 8, 2024 21:24:29', '104.28.163.27', 0, 67, 0, 213.028, -100.373, 1005.26, 15, 15, 1, 0, 0, 18, 160, 'Black', 'Black', 'Hazel', 'Invalid', 1, 'Nothing', 'Nothing', 5000, 5000, 0, 95415, 'December 9, 2024 10:30:34', 6, 0, 0, 0, 'None', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 338217, 0, 0, 3, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 1, 0, 0, 98.67, 98.06, 100, 100, 0, 0, 0, 0, 100, 100, 100, 100, 100, 100, 100, 100, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1),
(176, 109, 'Jack_Mashawn', 'HannB', 'December 8, 2024 21:31:59', '125.167.48.20', 0, 187, 0, 1967.92, -1280.66, 23.9844, 0, 0, 1, 0, 0, 21, 189, 'White', 'Black', 'Black', 'Invalid', 1, 'Nothing', 'Nothing', 10000, 5000, 0, 98749, 'December 8, 2024 22:23:54', 2, 0, 0, 0, 'None', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 391657, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 1, 0, 0, 95.74, 95.9, 100, 100, 0, 0, 0, 0, 100, 100, 100, 100, 100, 100, 100, 100, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1),
(162, 110, 'Astane_Diablo', 'Nazelaenak', 'December 8, 2024 22:25:37', '139.0.243.100', 0, 51, 0, 1625.14, -1739.2, 13.5469, 0, 0, 1, 0, 1, 18, 190, 'Black', 'Black', 'Black', 'Invalid', 1, 'Nothing', 'Nothing', 10000, 5000, 0, 100710, 'December 11, 2024 00:00:34', 3, 0, 0, 0, 'None', 0, 0, 0, 0, 0, 0, 0, 0, 0, 65535, 0, 304784, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 1, 0, 0, 96.02, 97.31, 100, 100, 0, 0, 0, 0, 100, 100, 100, 100, 100, 100, 100, 100, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1),
(118, 111, 'Kevin_Brooks', 'frengki', 'December 9, 2024 07:12:45', '180.252.89.83', 0, 51, 0, 1825.69, -1846.11, 13.4141, 0, 0, 1, 0, 0, 21, 184, 'Black', 'Black', 'Black', 'Invalid', 1, 'Nothing', 'Nothing', 10000, 5000, 0, 94834, 'December 9, 2024 10:23:11', 5, 0, 0, 0, 'None', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 297853, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 1, 0, 0, 98.63, 98.75, 100, 100, 0, 0, 0, 0, 100, 100, 100, 100, 100, 100, 100, 100, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1),
(174, 112, 'Gabriel_Poleon', 'Cyhna', 'December 9, 2024 14:19:47', '125.164.21.198', 0, 51, 0, 0, 0, 0, 0, 0, 1, 0, 1, 21, 184, 'Black', 'Black', 'Black', 'Invalid', 1, 'Nothing', 'Nothing', 10000, 5000, 0, 98069, 'December 9, 2024 17:25:02', 3, 0, 0, 0, 'None', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 302067, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 1, 0, 0, 99.47, 99.15, 100, 100, 0, 0, 0, 0, 100, 100, 100, 100, 100, 100, 100, 100, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1),
(145, 113, 'Brian_Jonhson', 'Brian1605', 'December 10, 2024 11:42:30', '180.253.185.137', 0, 163, 0, 2249.5, -1665.59, 15.4766, 15, 15, 1, 0, 0, 17, 186, 'Black', 'Black', 'Black', 'Invalid', 1, 'Nothing', 'Nothing', 20000, 5000, 0, 96169, 'December 10, 2024 14:13:31', 5, 0, 0, 0, 'None', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 324309, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 4, 1, 0, 0, 90.45, 90.3, 100, 100, 0, 0, 0, 0, 100, 100, 100, 100, 100, 100, 100, 100, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1),
(182, 114, 'Wenceslao_Moguel', 'Maradorios', 'December 10, 2024 14:14:50', '180.249.211.91', 0, 186, 0, 1652.12, -1518.54, 13.5469, 0, 0, 1, 0, 1, 19, 170, 'Latino', 'Bald', 'Hazel', 'Invalid', 1, 'Nothing', 'Nothing', 10000, 5000, 0, 94572, 'December 28, 2024 21:54:05', 4, 0, 0, 0, 'None', 0, 0, 0, 0, 0, 0, 0, 0, 0, 65535, 1, 395889, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 1, 0, 0, 85.73, 87.28, 100, 100, 0, 0, 0, 0, 100, 100, 100, 100, 100, 100, 100, 100, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1),
(182, 115, 'Wenceslao_Moguel', 'Maradorios', 'December 10, 2024 14:15:07', '180.249.211.91', 0, 186, 0, 0, 0, 0, 0, 0, 1, 0, 0, 19, 170, 'Latino', 'Bald', 'Hazel', 'Invalid', 1, 'Nothing', 'Nothing', 10000, 5000, 0, 100077, 'None', 0, 0, 0, 0, 'None', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 100, 100, 100, 100, 0, 0, 0, 0, 100, 100, 100, 100, 100, 100, 100, 100, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(182, 116, 'Wenceslao_Moguel', 'Maradorios', 'December 10, 2024 14:15:30', '180.249.211.91', 0, 186, 0, 0, 0, 0, 0, 0, 1, 0, 0, 19, 170, 'Latino', 'Bald', 'Hazel', 'Invalid', 1, 'Nothing', 'Nothing', 10000, 5000, 0, 98577, 'None', 0, 0, 0, 0, 'None', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 100, 100, 100, 100, 0, 0, 0, 0, 100, 100, 100, 100, 100, 100, 100, 100, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(163, 117, 'Jordan_Prince', 'Danzzzz', 'December 11, 2024 09:39:44', '114.122.101.33', 0, 181, 0, 2218.69, -1571.85, 23.5197, 0, 0, 1, 0, 0, 18, 170, 'Black', 'Black', 'Black', 'Invalid', 1, 'Nothing', 'Nothing', 10000, 5000, 0, 100541, 'December 11, 2024 10:07:26', 1, 0, 0, 0, 'None', 0, 0, 0, 0, 0, 0, 0, 0, 0, 65535, 0, 396102, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 1, 0, 0, 99.45, 99.16, 100, 100, 0, 0, 0, 0, 100, 100, 100, 100, 100, 100, 100, 100, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1),
(187, 118, 'DeAndre_Wright', 'Ccasper', 'December 11, 2024 10:07:41', '36.85.217.111', 0, 254, 0, 2227.45, -1333.51, 23.9844, 0, 0, 1, 0, 0, 25, 180, 'Black', 'Black', 'Black', 'Invalid', 1, 'Nothing', 'Nothing', 10000, 5000, 0, 97674, 'December 11, 2024 11:40:36', 1, 0, 0, 0, 'None', 0, 0, 0, 0, 0, 0, 0, 0, 0, 65535, 0, 298701, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 1, 0, 0, 98.86, 99.01, 100, 100, 0, 0, 0, 0, 100, 100, 100, 100, 100, 100, 100, 100, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1),
(188, 119, 'Julius_Clayton', 'KillaMachina', 'December 12, 2024 05:09:40', '125.164.130.200', 0, 293, 0, 2118.8, -1761.85, 13.3984, 0, 0, 1, 0, 0, 17, 175, 'Black', 'Black', 'Brown', 'Invalid', 1, 'Nothing', 'Nothing', 6900, 5000, 0, 100402, 'December 13, 2024 15:42:10', 6, 0, 0, 0, 'None', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 337335, 0, 0, 0, 0, 0, 0, 1, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 1, 0, 0, 86.75, 87.63, 50, 100, 0, 0, 0, 0, 91, 100, 100, 100, 100, 1, 100, 100, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1),
(188, 120, 'Julius_Clayton', 'KillaMachina', 'December 12, 2024 05:09:51', '125.164.130.200', 0, 45, 0, 0, 0, 0, 0, 0, 1, 0, 0, 17, 175, 'Black', 'Black', 'Brown', 'Invalid', 1, 'Nothing', 'Nothing', 10000, 5000, 0, 99305, 'None', 0, 0, 0, 0, 'None', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 100, 100, 100, 100, 0, 0, 0, 0, 100, 100, 100, 100, 100, 100, 100, 100, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(189, 121, 'Ladaler_Pattom', 'rapha', 'December 12, 2024 15:53:40', '110.138.93.29', 0, 20004, 0, 2234.48, -1295.15, 23.9789, 0, 0, 1, 0, 0, 27, 186, 'Latino', 'Black', 'Brown', 'Invalid', 1, 'Nothing', 'Nothing', 10000, 5000, 0, 99449, 'December 12, 2024 15:55:34', 3, 0, 0, 0, 'None', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 354677, 0, 0, 0, 0, 0, 0, 1, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 1, 0, 0, 99.53, 99.84, 100, 100, 0, 0, 0, 0, 100, 100, 100, 100, 100, 100, 100, 100, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1),
(191, 122, 'Barrax_Carras', 'babakbelur', 'December 13, 2024 15:05:36', '180.251.244.33', 0, 132, 0, 2213.44, -1379.78, 23.8281, 0, 0, 1, 0, 0, 24, 186, 'White', 'Black', 'Brown', 'Invalid', 1, 'Nothing', 'Nothing', 10000, 5000, 0, 98420, 'December 13, 2024 15:07:56', 2, 0, 0, 0, 'None', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 320572, 0, 0, 0, 0, 0, 0, 1, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 1, 0, 0, 99.02, 99.23, 100, 100, 0, 0, 0, 0, 100, 100, 100, 100, 100, 100, 100, 100, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1),
(178, 123, 'Darin_Pierre', 'Blumners', 'December 13, 2024 18:58:44', '202.169.232.180', 0, 20012, 0, 2739.1, -2451.03, 13.6484, 0, 0, 1, 0, 1, 19, 189, 'Black', 'Black', 'Brown', 'Invalid', 1, 'Nothing', 'Nothing', 24400, 5000, 0, 94183, 'December 13, 2024 19:34:48', 38, 0, 0, 0, 'None', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 238889, 0, 0, 0, 0, 0, 0, 1, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 1, 0, 0, 81.02, 82.14, 96, 100, 0, 0, 0, 0, 87, 100, 100, 100, 100, 100, 100, 100, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1),
(197, 124, 'Jevoky_Holt', 'Kemaluan', 'December 15, 2024 15:32:09', '114.10.122.41', 0, 59, 0, 2443.37, -1936.65, 12.8922, 0, 0, 1, 0, 1, 18, 180, 'Black', 'Black', 'Black', 'Invalid', 1, 'Nothing', 'Nothing', 5000, 5000, 0, 94982, 'December 30, 2024 18:49:46', 10, 0, 0, 0, 'None', 0, 0, 0, 117, 0, 0, 0, 0, 1, 5, 1, 228238, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 1, 0, 0, 84.47, 99.81, 100, 100, 0, 0, 0, 0, 100, 100, 100, 100, 100, 100, 100, 100, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1),
(202, 125, 'Waston_Pought', 'FromPluto', 'December 17, 2024 08:52:08', '223.25.110.217', 0, 109, 0, 691.759, -1570.35, 14.2422, 0, 0, 1, 0, 0, 19, 170, 'White', 'Black', 'Black', 'Invalid', 1, 'Nothing', 'Nothing', 10000, 5000, 0, 96553, 'January 1, 2025 14:47:32', 3, 0, 0, 0, 'None', 0, 0, 0, 110, 0, 0, 0, 0, 1, 8, 0, 286532, 0, 0, 0, 0, 0, 0, 1, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 1, 0, 0, 85.48, 87.4, 100, 100, 0, 0, 0, 0, 100, 100, 100, 100, 100, 100, 100, 100, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1),
(204, 126, 'Henry_Jefford', 'watts', 'December 17, 2024 09:23:30', '120.188.92.196', 0, 20012, 0, 1655.33, -1512.32, 13.3828, 0, 0, 1, 0, 0, 21, 173, 'Latino', 'Black', 'Black', 'Invalid', 1, 'Nothing', 'Nothing', 10000, 5000, 0, 96745, 'December 17, 2024 13:43:17', 1, 0, 0, 0, 'None', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 305245, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 1, 0, 0, 99.13, 99.41, 100, 100, 0, 0, 0, 0, 100, 100, 100, 100, 100, 100, 100, 100, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1),
(205, 127, 'Dalbert_Wemington', 'MABARGTA', 'December 17, 2024 11:25:40', '182.3.72.120', 0, 133, 0, 1655.43, -1504.71, 13.3828, 0, 0, 1, 0, 0, 19, 166, 'Black', 'Red', 'Gray', 'Invalid', 1, 'Nothing', 'Nothing', 10000, 5000, 0, 97429, 'December 17, 2024 11:30:10', 1, 0, 0, 0, 'None', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 288364, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 1, 0, 0, 97.82, 97.75, 100, 100, 0, 0, 0, 0, 100, 100, 100, 100, 100, 100, 100, 100, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1),
(199, 128, 'Juan_Maress', 'kudanel', 'December 17, 2024 16:15:29', '182.2.52.114', 0, 117, 0, 510.721, -83.3603, 998.961, 11, 11, 1, 0, 0, 19, 186, 'White', 'Bald', 'Black', 'Invalid', 1, 'Nothing', 'Nothing', 8000, 5000, 0, 95890, 'December 17, 2024 16:20:51', 6, 0, 0, 0, 'None', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 363933, 0, 0, 7, 0, 0, 0, 1, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 1, 0, 0, 98.25, 97.84, 100, 100, 0, 0, 0, 0, 100, 100, 100, 100, 100, 100, 100, 100, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1),
(207, 129, 'Elijah_Benjamin', 'Ryonaldho', 'December 17, 2024 22:37:50', '180.253.155.2', 0, 21, 0, 885.533, -1219.33, 16.9836, 0, 0, 1, 0, 0, 24, 186, 'Black', 'Black', 'Black', 'Invalid', 1, 'Nothing', 'Nothing', 6900, 5000, 0, 98083, 'December 22, 2024 20:20:46', 8, 0, 0, 0, 'None', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 277473, 0, 0, 0, 0, 0, 0, 1, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 1, 0, 0, 79.47, 80.35, 100, 100, 0, 0, 0, 0, 100, 100, 100, 100, 100, 100, 100, 100, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1),
(208, 130, 'Adam_William', 'DamDmw', 'December 19, 2024 11:20:42', '182.1.19.252', 0, 183, 0, 1845.7, -1870.75, 13.2972, 0, 0, 1, 0, 0, 17, 186, 'White', 'Bald', 'Black', 'Invalid', 1, 'Nothing', 'Nothing', 35000, 5000, 0, 97223, 'December 20, 2024 14:41:01', 5, 0, 0, 0, 'None', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 252491, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 1, 0, 0, 94.83, 95.19, 95, 100, 0, 0, 0, 0, 100, 100, 100, 100, 100, 100, 100, 100, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1),
(134, 131, 'David_Kenword', 'Hobigtasa', 'December 20, 2024 16:40:58', '180.242.215.160', 0, 20003, 0, 2140.91, -1751.68, 13.3952, 0, 0, 1, 0, 0, 29, 186, 'White', 'Bald', 'Black', 'Invalid', 1, 'Nothing', 'Nothing', 6900, 5000, 0, 98577, 'December 22, 2024 11:43:39', 5, 0, 0, 0, 'None', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 246621, 0, 0, 0, 0, 0, 0, 1, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 1, 0, 0, 95.61, 95.46, 50, 100, 0, 0, 0, 0, 0, 100, 100, 100, 100, 1, 100, 100, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1),
(210, 132, 'Cicks_Lobbs', 'yOungbie', 'December 21, 2024 23:18:57', '180.251.202.29', 0, 294, 0, 0, 0, -105.106, 0, 0, 1, 0, 0, 24, 187, 'Black', 'Brown', 'Hazel', 'Invalid', 1, 'Nothing', 'Nothing', 10000, 5000, 0, 96360, 'December 21, 2024 23:19:38', 4, 0, 0, 0, 'None', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 335714, 0, 0, 0, 0, 0, 0, 1, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 1, 1, 0, 99.33, 99.11, 100, 100, 0, 0, 0, 0, 56, 100, 100, 100, 100, 1, 100, 100, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1),
(211, 133, 'Tyson_Kennedy', 'youton', 'December 22, 2024 10:10:23', '140.213.41.96', 0, 258, 0, 1672.09, -1587.31, 13.5469, 0, 0, 1, 0, 0, 25, 180, 'Black', 'Black', 'Brown', 'Invalid', 1, 'Nothing', 'Nothing', 10000, 5000, 0, 95947, 'December 22, 2024 11:08:48', 0, 0, 0, 0, 'None', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 380822, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 1, 0, 0, 98.11, 99.3, 100, 100, 0, 0, 0, 0, 100, 100, 100, 100, 100, 100, 100, 100, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1),
(213, 134, 'Ryder_Pankeztone', 'Pankeztone', 'December 22, 2024 16:27:26', '182.2.51.201', 0, 258, 0, -50.2443, 34.1588, 2.70774, 0, 0, 1, 0, 1, 21, 171, 'Asian', 'Black', 'Brown', 'Invalid', 1, 'Nothing', 'Nothing', 5000, 5000, 0, 94546, 'December 22, 2024 16:59:21', 35, 0, 0, 0, 'None', 0, 0, 0, 108, 0, 0, 0, 0, 1, 11, 1, 366855, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 1, 0, 0, 84.83, 83.84, 40, 100, 0, 0, 0, 0, 0, 100, 100, 100, 100, 1, 100, 100, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1),
(214, 135, 'Yamori_Dixon', 'yamoridixon', 'December 22, 2024 19:28:58', '180.242.194.250', 0, 57, 0, 2660.86, -1679.53, 9.59466, 0, 0, 1, 0, 0, 60, 180, 'Asian', 'Red', 'Black', 'Invalid', 1, 'Nothing', 'Nothing', 39100, 5000, 0, 97995, 'December 22, 2024 20:08:30', 44, 0, 0, 0, 'None', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 300893, 0, 0, 0, 0, 0, 0, 1, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 1, 0, 0, 83.67, 83.29, 100, 100, 0, 0, 0, 0, 100, 100, 100, 100, 100, 100, 100, 100, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1),
(209, 136, 'Graphel_Landegre', 'Hammer', 'December 22, 2024 19:56:25', '158.140.182.88', 0, 20007, 0, 1286.97, 1598.48, 455.25, 11, 6830, 1, 0, 0, 34, 186, 'White', 'Brown', 'Blue', 'Invalid', 1, 'Nothing', 'Nothing', 10000, 5000, 0, 96941, 'December 22, 2024 20:08:56', 17, 0, 0, 0, 'None', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 255888, 0, 0, 4, 0, 0, 0, 1, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 1, 0, 0, 99.16, 98.83, 100, 100, 0, 0, 0, 0, 100, 100, 100, 100, 100, 100, 100, 100, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1),
(215, 137, 'Nazmit_Brooks', 'Starboyy', 'December 22, 2024 20:12:26', '36.85.223.182', 0, 132, 0, 1789.01, -1597.58, 13.5165, 0, 0, 1, 0, 0, 18, 160, 'Asian', 'Gray', 'Brown', 'Invalid', 1, 'Nothing', 'Nothing', 10000, 5000, 0, 97570, 'December 22, 2024 20:20:15', 8, 0, 0, 0, 'None', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 320079, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 1, 0, 0, 97.07, 94.68, 98, 100, 0, 0, 0, 0, 94, 100, 100, 100, 100, 100, 100, 100, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1),
(218, 138, 'Rasheed_Morkel', 'violentvira', 'December 23, 2024 09:48:29', '114.10.44.81', 0, 7, 0, 2611.86, -2433.2, 13.6384, 0, 0, 1, 0, 0, 18, 183, 'Black', 'Black', 'Brown', 'Invalid', 1, 'Nothing', 'Nothing', 149790, 5000, 0, 96103, 'December 27, 2024 20:36:29', 21, 0, 0, 0, 'None', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 241980, 0, 0, 0, 0, 0, 0, 1, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 1, 0, 0, 61.84, 73.15, 100, 100, 0, 0, 0, 0, 100, 100, 100, 100, 100, 100, 100, 100, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1),
(176, 139, 'Graham_Lamar', 'Hannb', 'December 23, 2024 20:54:23', '103.175.229.237', 0, 51, 0, 1795.86, -1614.68, 13.4434, 0, 0, 1, 0, 0, 19, 187, 'Black', 'Black', 'Brown', 'Invalid', 1, 'Nothing', 'Nothing', 35000, 5000, 0, 98343, 'December 23, 2024 21:03:24', 12, 0, 0, 0, 'None', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 300240, 0, 0, 0, 0, 0, 0, 1, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 1, 0, 0, 94.78, 95.15, 100, 100, 0, 0, 0, 0, 100, 100, 100, 100, 100, 100, 100, 100, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1),
(222, 140, 'Josue_Vargas', 'bullran', 'December 25, 2024 17:00:48', '180.242.70.138', 0, 20017, 0, 1752.55, -1435.79, 13.5469, 0, 0, 1, 0, 1, 21, 189, 'Latino', 'Brown', 'Black', 'Invalid', 1, 'Nothing', 'Nothing', 88400, 5000, 0, 100459, 'December 30, 2024 22:56:25', 25, 0, 0, 0, 'None', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 377669, 0, 0, 0, 0, 0, 0, 1, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 1, 0, 0, 81.2001, 94.21, 100, 100, 0, 0, 0, 0, 100, 100, 100, 100, 100, 100, 100, 100, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10, 0, 1),
(222, 141, 'Josue_Vargas', 'bullran', 'December 25, 2024 17:01:02', '180.242.70.138', 0, 20017, 0, 0, 0, 0, 0, 0, 1, 0, 0, 21, 189, 'Latino', 'Brown', 'Black', 'Invalid', 1, 'Nothing', 'Nothing', 10000, 5000, 0, 99200, 'None', 0, 0, 0, 0, 'None', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 100, 100, 100, 100, 0, 0, 0, 0, 100, 100, 100, 100, 100, 100, 100, 100, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(216, 142, 'Jack_Reacher', 'Salsaxy', 'December 26, 2024 17:33:21', '103.147.82.234', 0, 20017, 302, 253.489, 80.036, 1003.64, 6, 24518, 1, 0, 2, 23, 180, 'Black', 'Blonde', 'Blue', 'Invalid', 1, 'Nothing', 'Nothing', 14300, 10000, 1000, 97771, 'December 29, 2024 16:07:39', 2, 0, 0, 0, 'None', 1, 4, 0, 113, 114, 0, 0, 0, 1, 11, 2, 228754, 0, 0, 0, 1, 0, 0, 1, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 1, 0, 0, 38.8301, 71.5399, 100, 100, 100, 0, 0, 0, 100, 100, 100, 100, 100, 100, 100, 100, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1),
(223, 143, 'Santa_Malerez', 'sntcrxz', 'December 26, 2024 17:53:57', '110.138.80.155', 0, 185, 0, 2099.04, -1804.61, 13.5545, 0, 0, 1, 0, 0, 20, 172, 'Latino', 'Black', 'Gray', 'Invalid', 1, 'Nothing', 'Nothing', 40100, 5000, 0, 97215, 'December 30, 2024 01:09:35', 2, 0, 0, 0, 'None', 0, 0, 0, 112, 0, 0, 0, 0, 0, 0, 0, 308315, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 1, 0, 0, 88.8201, 79.1099, 100, 100, 0, 0, 0, 0, 100, 100, 100, 100, 100, 100, 100, 100, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1),
(226, 144, 'David_Harrystone', 'Borisu', 'December 27, 2024 21:05:31', '180.245.13.4', 0, 32, 0, 1859.35, -1452.13, 13.5625, 0, 0, 1, 0, 0, 23, 186, 'Black', 'Brown', 'Gray', 'Invalid', 1, 'Nothing', 'Nothing', 10000, 5000, 0, 99113, 'December 27, 2024 21:06:43', 4, 0, 0, 0, 'None', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 368098, 0, 0, 0, 0, 0, 0, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 1, 0, 0, 99.31, 99.13, 100, 100, 0, 0, 0, 0, 100, 100, 100, 100, 100, 100, 100, 100, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1),
(227, 145, 'Tashound_Glendour', 'fahrizal', 'December 29, 2024 02:15:31', '36.79.190.206', 0, 32, 0, 1965.27, -1461.91, 13.3946, 0, 0, 1, 0, 0, 24, 170, 'Black', 'Brown', 'Gray', 'Invalid', 1, 'Nothing', 'Nothing', 10000, 5000, 0, 99596, 'December 30, 2024 22:27:44', 2, 0, 0, 0, 'None', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 301744, 0, 0, 0, 0, 0, 0, 1, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 1, 0, 0, 98.68, 99.87, 100, 100, 0, 0, 0, 0, 91, 100, 100, 100, 100, 1, 100, 100, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1),
(141, 146, 'Sabrina_Carpenter', 'randz', 'December 29, 2024 11:18:24', '180.249.203.59', 0, 91, 0, 0, 0, -100.731, 0, 0, 1, 0, 0, 24, 170, 'Black', 'Brown', 'Gray', 'Invalid', 2, 'Nothing', 'Nothing', 10000, 5000, 0, 97040, 'December 29, 2024 11:18:50', 0, 0, 0, 0, 'None', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 281309, 0, 0, 0, 0, 0, 0, 1, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 1, 1, 0, 99.69, 99.04, 100, 100, 0, 0, 0, 0, 100, 100, 100, 100, 100, 100, 100, 100, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1),
(228, 147, 'Knox_Shaw', 'Auren', 'December 29, 2024 18:30:03', '114.122.109.195', 0, 46, 0, 1671.94, -1542.22, 13.5469, 0, 0, 1, 0, 0, 20, 190, 'White', 'Black', 'Black', 'Invalid', 1, 'Nothing', 'Nothing', 10000, 5000, 0, 94820, 'December 29, 2024 18:30:41', 4, 0, 0, 0, 'None', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 226435, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 1, 0, 0, 99.56, 100, 100, 100, 0, 0, 0, 0, 100, 100, 100, 100, 100, 100, 100, 100, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1),
(229, 148, 'Felix_Pernand', 'Cikuya', 'December 30, 2024 00:59:59', '103.115.20.39', 0, 4, 0, 1622.76, -1782.15, 13.5173, 0, 0, 1, 0, 0, 19, 170, 'White', 'Bald', 'Black', 'Invalid', 1, 'Nothing', 'Nothing', 34500, 5000, 0, 98839, 'December 30, 2024 01:12:07', 12, 0, 0, 0, 'None', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 249277, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 1, 0, 0, 94.76, 100, 100, 100, 0, 0, 0, 0, 100, 100, 100, 100, 100, 100, 100, 100, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1),
(230, 149, 'Diego_Carlos', 'adaaam', 'December 30, 2024 06:03:32', '125.163.74.241', 0, 109, 0, 1485.93, -1738.16, 13.5469, 0, 0, 1, 0, 0, 18, 175, 'Latino', 'Black', 'Black', 'Invalid', 1, 'Nothing', 'Nothing', 10000, 5000, 0, 99277, 'December 30, 2024 06:09:05', 4, 0, 0, 0, 'None', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 382656, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 1, 0, 0, 98.35, 100, 100, 100, 0, 0, 0, 0, 100, 100, 100, 100, 100, 100, 100, 100, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1),
(227, 150, 'Felix_Pernand', 'fahrizal', 'December 30, 2024 22:22:56', '36.79.190.206', 0, 160, 0, 0, 0, 0, 0, 0, 1, 0, 0, 18, 170, 'White', 'Black', 'Black', 'Invalid', 1, 'Nothing', 'Nothing', 10000, 5000, 0, 100601, 'None', 0, 0, 0, 0, 'None', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 100, 100, 100, 100, 0, 0, 0, 0, 100, 100, 100, 100, 100, 100, 100, 100, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(233, 151, 'Vincenzo_Castallos', 'Arikk', 'January 1, 2025 17:47:54', '178.128.16.61', 0, 109, 0, 1648.76, -1583.56, 13.5304, 0, 0, 1, 0, 0, 19, 179, 'Latino', 'Black', 'Black', 'Invalid', 1, 'Nothing', 'Nothing', 35000, 5000, 0, 94881, 'January 1, 2025 17:51:38', 4, 0, 0, 0, 'None', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 286260, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 1, 0, 0, 98.6, 100, 100, 100, 0, 0, 0, 0, 100, 100, 100, 100, 100, 100, 100, 100, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1);

-- --------------------------------------------------------

--
-- Table structure for table `compensation_claims`
--

CREATE TABLE `compensation_claims` (
  `player_id` int(11) NOT NULL,
  `code` varchar(32) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

-- --------------------------------------------------------

--
-- Table structure for table `compensation_codes`
--

CREATE TABLE `compensation_codes` (
  `id` int(11) NOT NULL,
  `code` varchar(32) NOT NULL DEFAULT 'None',
  `max_players` int(11) NOT NULL DEFAULT 0,
  `expired` int(11) NOT NULL DEFAULT 0,
  `money` int(11) NOT NULL DEFAULT 0,
  `street_credits` int(11) NOT NULL DEFAULT 0,
  `players_used` int(11) NOT NULL DEFAULT 0
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

-- --------------------------------------------------------

--
-- Table structure for table `contacts`
--

CREATE TABLE `contacts` (
  `ID` int(11) NOT NULL DEFAULT 0,
  `contactName` varchar(32) NOT NULL DEFAULT 'none',
  `contactID` int(11) NOT NULL DEFAULT 0,
  `contactNumber` int(11) NOT NULL DEFAULT 0
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

-- --------------------------------------------------------

--
-- Table structure for table `court`
--

CREATE TABLE `court` (
  `ID` int(11) NOT NULL,
  `ballx` float NOT NULL DEFAULT 0,
  `bally` float NOT NULL DEFAULT 0,
  `ballz` float NOT NULL DEFAULT 0,
  `bluex` float NOT NULL DEFAULT 0,
  `bluey` float NOT NULL DEFAULT 0,
  `bluez` float NOT NULL DEFAULT 0,
  `redx` float NOT NULL DEFAULT 0,
  `redy` float NOT NULL DEFAULT 0,
  `redz` float NOT NULL DEFAULT 0,
  `bluebx` float NOT NULL DEFAULT 0,
  `blueby` float NOT NULL DEFAULT 0,
  `bluebz` float NOT NULL DEFAULT 0,
  `redbx` float NOT NULL DEFAULT 0,
  `redby` float NOT NULL DEFAULT 0,
  `redbz` float NOT NULL DEFAULT 0
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `court`
--

INSERT INTO `court` (`ID`, `ballx`, `bally`, `ballz`, `bluex`, `bluey`, `bluez`, `redx`, `redy`, `redz`, `bluebx`, `blueby`, `bluebz`, `redbx`, `redby`, `redbz`) VALUES
(8, 2782.63, -2019.62, 12.7547, 0, 0, 0, 2768.91, -2019.68, 12.7547, 0, 0, 0, 2768.67, -2019.72, 15.4847);

-- --------------------------------------------------------

--
-- Table structure for table `criminal_record`
--

CREATE TABLE `criminal_record` (
  `idx` int(11) NOT NULL,
  `player_name` varchar(32) NOT NULL DEFAULT 'None',
  `charge_reason` varchar(128) NOT NULL DEFAULT 'None',
  `add_date` varchar(90) NOT NULL DEFAULT 'None'
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COLLATE=latin1_swedish_ci;

--
-- Dumping data for table `criminal_record`
--

INSERT INTO `criminal_record` (`idx`, `player_name`, `charge_reason`, `add_date`) VALUES
(22, 'Radeetz', 'lorem ipsum', 'July 10, 2024 20:51:57'),
(23, 'Blixkyy', 'Grand Theft Auto', 'July 11, 2024 11:54:27'),
(24, 'Jayvon_Williams', 'Sex Harrasment', 'November 29, 2024 19:35:33'),
(25, 'Joseph_Vier', 'Kidnapping', 'December 23, 2024 20:58:31'),
(26, 'Joseph_Vier', 'Drive-By Shooting', 'December 24, 2024 00:56:28'),
(27, 'Brayn_Conwell', 'Possession Of An Unlicensed Firearm', 'December 26, 2024 20:02:31'),
(28, 'Ethan_Pattersons', 'Sex Harassment', 'December 29, 2024 13:44:49'),
(29, 'Ethan_Pattersons', 'Sexual Battery', 'December 29, 2024 13:53:34');

-- --------------------------------------------------------

--
-- Table structure for table `dropped`
--

CREATE TABLE `dropped` (
  `ID` int(12) NOT NULL,
  `itemName` varchar(32) DEFAULT NULL,
  `itemModel` int(12) DEFAULT 0,
  `itemX` float DEFAULT 0,
  `itemY` float DEFAULT 0,
  `itemZ` float DEFAULT 0,
  `itemRX` float DEFAULT 0,
  `itemRY` float DEFAULT 0,
  `itemRZ` float DEFAULT 0,
  `itemInt` int(12) DEFAULT 0,
  `itemWorld` int(12) DEFAULT 0,
  `itemQuantity` int(12) DEFAULT 0,
  `itemAmount` int(12) DEFAULT 0,
  `itemType` int(12) DEFAULT 0,
  `itemPlayer` varchar(24) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COLLATE=latin1_swedish_ci;

--
-- Dumping data for table `dropped`
--

INSERT INTO `dropped` (`ID`, `itemName`, `itemModel`, `itemX`, `itemY`, `itemZ`, `itemRX`, `itemRY`, `itemRZ`, `itemInt`, `itemWorld`, `itemQuantity`, `itemAmount`, `itemType`, `itemPlayer`) VALUES
(170, 'Cutscene Bat', 19914, 1290.79, 1567.98, 454.35, 0, 0, 0, 11, 6817, 1, 0, 0, 'Joseph Vier'),
(171, 'Spike Bat', 2045, 1291.01, 1573.31, 454.35, 0, 0, 0, 11, 6817, 1, 0, 0, 'Joseph Vier'),
(174, 'Hammer', 18635, 1969.99, -1269.57, 23.0843, 0, 0, 0, 0, 0, 1, 0, 0, 'Joseph Vier'),
(175, 'Broom', 19622, 1969.6, -1269.54, 23.0843, 0, 0, 0, 0, 0, 1, 0, 0, 'Joseph Vier'),
(176, 'Desert Eagle', 348, 1776.79, -1602.73, 12.6468, 0, 0, 0, 0, 0, 1, 0, 0, 'Giovanna Rodriguez'),
(177, 'Fabric Cargo', 2912, 821.628, -600.772, 15.4359, 0, 0, 0, 0, 0, 1, 0, 0, 'Brayn Conwell'),
(180, 'Appliances Cargo', 2912, 858.467, -1211.9, 15.9265, 0, 0, 0, 0, 0, 1, 0, 0, 'Ethan Pattersons');

-- --------------------------------------------------------

--
-- Table structure for table `entrance`
--

CREATE TABLE `entrance` (
  `ID` int(11) NOT NULL,
  `posx` float NOT NULL DEFAULT 0,
  `posy` float NOT NULL DEFAULT 0,
  `posz` float NOT NULL DEFAULT 0,
  `intx` float NOT NULL DEFAULT 0,
  `inty` float NOT NULL DEFAULT 0,
  `intz` float NOT NULL DEFAULT 0,
  `interior` int(11) NOT NULL DEFAULT 0,
  `world` int(11) NOT NULL DEFAULT 0,
  `icon` int(11) NOT NULL DEFAULT 0,
  `garage` int(11) NOT NULL DEFAULT 0
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `entrance`
--

INSERT INTO `entrance` (`ID`, `posx`, `posy`, `posz`, `intx`, `inty`, `intz`, `interior`, `world`, `icon`, `garage`) VALUES
(1, 1554.81, -1675.61, 16.1953, 246.771, 62.628, 1003.64, 6, 24518, 30, 0),
(2, 2034.05, -1402.26, 17.2936, 1849.65, -1072.56, 41.6537, 1, 15241, 22, 0),
(3, 1798.07, -1578.85, 14.0916, 1260.11, 896.423, 1161.1, 6, 3028, 40, 0),
(4, 1172.66, -1323.34, 15.4025, 1266.56, -1291.42, 1061.15, 6, 16034, 22, 0);

-- --------------------------------------------------------

--
-- Table structure for table `factions`
--

CREATE TABLE `factions` (
  `DBID` int(11) NOT NULL,
  `FactionName` varchar(90) NOT NULL DEFAULT 'None',
  `FactionAbbrev` varchar(30) NOT NULL DEFAULT 'None',
  `FactionSpawnX` float NOT NULL DEFAULT 0,
  `FactionSpawnY` float NOT NULL DEFAULT 0,
  `FactionSpawnZ` float NOT NULL DEFAULT 0,
  `FactionInterior` int(11) NOT NULL DEFAULT 0,
  `FactionWorld` int(11) NOT NULL DEFAULT 0,
  `FactionJoinRank` int(11) NOT NULL DEFAULT 0,
  `FactionAlterRank` int(11) NOT NULL DEFAULT 0,
  `FactionChatRank` int(11) NOT NULL DEFAULT 0,
  `FactionTowRank` int(11) NOT NULL DEFAULT 0,
  `FactionChatColor` int(11) NOT NULL DEFAULT 0,
  `FactionType` tinyint(4) NOT NULL DEFAULT 0,
  `FactionInteriorId` int(11) NOT NULL DEFAULT 0,
  `FactionInteriorWorld` int(11) NOT NULL DEFAULT 0,
  `FactionTurfTokens` int(11) NOT NULL DEFAULT 0,
  `FactionDrugs` int(11) NOT NULL DEFAULT 0
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COLLATE=latin1_swedish_ci;

--
-- Dumping data for table `factions`
--

INSERT INTO `factions` (`DBID`, `FactionName`, `FactionAbbrev`, `FactionSpawnX`, `FactionSpawnY`, `FactionSpawnZ`, `FactionInterior`, `FactionWorld`, `FactionJoinRank`, `FactionAlterRank`, `FactionChatRank`, `FactionTowRank`, `FactionChatColor`, `FactionType`, `FactionInteriorId`, `FactionInteriorWorld`, `FactionTurfTokens`, `FactionDrugs`) VALUES
(4, 'San Andreas Police Departement', 'SAPD', 1546.82, -1668.81, 13.5665, 0, 0, 0, 0, 0, 0, -1920073729, 2, 6, 0, 1, 30),
(5, 'San Andreas Medical Departement', 'SAMD', 1184.09, -1333.22, 13.5804, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0, 1, 30);

-- --------------------------------------------------------

--
-- Table structure for table `faction_ranks`
--

CREATE TABLE `faction_ranks` (
  `factionid` int(11) NOT NULL,
  `FactionRank1` varchar(60) NOT NULL DEFAULT 'NotSet',
  `FactionRank2` varchar(60) NOT NULL DEFAULT 'NotSet',
  `FactionRank3` varchar(60) NOT NULL DEFAULT 'NotSet',
  `FactionRank4` varchar(60) NOT NULL DEFAULT 'NotSet',
  `FactionRank5` varchar(60) NOT NULL DEFAULT 'NotSet',
  `FactionRank6` varchar(60) NOT NULL DEFAULT 'NotSet',
  `FactionRank7` varchar(60) NOT NULL DEFAULT 'NotSet',
  `FactionRank8` varchar(60) NOT NULL DEFAULT 'NotSet',
  `FactionRank9` varchar(60) NOT NULL DEFAULT 'NotSet',
  `FactionRank10` varchar(60) NOT NULL DEFAULT 'NotSet',
  `FactionRank11` varchar(60) NOT NULL DEFAULT 'NotSet',
  `FactionRank12` varchar(60) NOT NULL DEFAULT 'NotSet',
  `FactionRank13` varchar(60) NOT NULL DEFAULT 'NotSet',
  `FactionRank14` varchar(60) NOT NULL DEFAULT 'NotSet',
  `FactionRank15` varchar(60) NOT NULL DEFAULT 'NotSet',
  `FactionRank16` varchar(60) NOT NULL DEFAULT 'NotSet',
  `FactionRank17` varchar(60) NOT NULL DEFAULT 'NotSet',
  `FactionRank18` varchar(60) NOT NULL DEFAULT 'NotSet',
  `FactionRank19` varchar(60) NOT NULL DEFAULT 'NotSet',
  `FactionRank20` varchar(60) NOT NULL DEFAULT 'NotSet'
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COLLATE=latin1_swedish_ci;

--
-- Dumping data for table `faction_ranks`
--

INSERT INTO `faction_ranks` (`factionid`, `FactionRank1`, `FactionRank2`, `FactionRank3`, `FactionRank4`, `FactionRank5`, `FactionRank6`, `FactionRank7`, `FactionRank8`, `FactionRank9`, `FactionRank10`, `FactionRank11`, `FactionRank12`, `FactionRank13`, `FactionRank14`, `FactionRank15`, `FactionRank16`, `FactionRank17`, `FactionRank18`, `FactionRank19`, `FactionRank20`) VALUES
(15, 'NotSet', 'NotSet', 'NotSet', 'NotSet', 'NotSet', 'NotSet', 'NotSet', 'NotSet', 'NotSet', 'NotSet', 'NotSet', 'NotSet', 'NotSet', 'NotSet', 'NotSet', 'NotSet', 'NotSet', 'NotSet', 'NotSet', 'NotSet');

-- --------------------------------------------------------

--
-- Table structure for table `furniture`
--

CREATE TABLE `furniture` (
  `id` int(11) NOT NULL,
  `propertydbid` int(11) DEFAULT 0,
  `modelid` smallint(5) DEFAULT 0,
  `name` varchar(32) DEFAULT 'None',
  `price` int(10) DEFAULT 0,
  `type` int(11) NOT NULL DEFAULT 0,
  `pos_x` float DEFAULT 0,
  `pos_y` float DEFAULT 0,
  `pos_z` float DEFAULT 0,
  `rot_x` float DEFAULT 0,
  `rot_y` float DEFAULT 0,
  `rot_z` float DEFAULT 0,
  `interior` tinyint(2) DEFAULT 0,
  `world` int(10) DEFAULT 0,
  `door_opened` tinyint(1) DEFAULT 0,
  `door_locked` tinyint(1) DEFAULT 0,
  `matModel0` int(11) NOT NULL DEFAULT 0,
  `matModel1` int(11) NOT NULL DEFAULT 0,
  `matModel2` int(11) NOT NULL DEFAULT 0,
  `matModel3` int(11) NOT NULL DEFAULT 0,
  `matModel4` int(11) NOT NULL DEFAULT 0,
  `matModel5` int(11) NOT NULL DEFAULT 0,
  `matModel6` int(11) NOT NULL DEFAULT 0,
  `matModel7` int(11) NOT NULL DEFAULT 0,
  `matModel8` int(11) NOT NULL DEFAULT 0,
  `matModel9` int(11) NOT NULL DEFAULT 0,
  `matModel10` int(11) NOT NULL DEFAULT 0,
  `matModel11` int(11) NOT NULL DEFAULT 0,
  `matModel12` int(11) NOT NULL DEFAULT 0,
  `matModel13` int(11) NOT NULL DEFAULT 0,
  `matModel14` int(11) NOT NULL DEFAULT 0,
  `matTxd0` varchar(32) NOT NULL DEFAULT 'None',
  `matTxd1` varchar(32) NOT NULL DEFAULT 'None',
  `matTxd2` varchar(32) NOT NULL DEFAULT 'None',
  `matTxd3` varchar(32) NOT NULL DEFAULT 'None',
  `matTxd4` varchar(32) NOT NULL DEFAULT 'None',
  `matTxd5` varchar(32) NOT NULL DEFAULT 'None',
  `matTxd6` varchar(32) NOT NULL DEFAULT 'None',
  `matTxd7` varchar(32) NOT NULL DEFAULT 'None',
  `matTxd8` varchar(32) NOT NULL DEFAULT 'None',
  `matTxd9` varchar(32) NOT NULL DEFAULT 'None',
  `matTxd10` varchar(32) NOT NULL DEFAULT 'None',
  `matTxd11` varchar(32) NOT NULL DEFAULT 'None',
  `matTxd12` varchar(32) NOT NULL DEFAULT 'None',
  `matTxd13` varchar(32) NOT NULL DEFAULT 'None',
  `matTxd14` varchar(32) NOT NULL DEFAULT 'None',
  `matTexture0` varchar(32) NOT NULL,
  `matTexture1` varchar(32) NOT NULL DEFAULT 'None',
  `matTexture2` varchar(32) NOT NULL DEFAULT 'None',
  `matTexture3` varchar(32) NOT NULL DEFAULT 'None',
  `matTexture4` varchar(32) NOT NULL DEFAULT 'None',
  `matTexture5` varchar(32) NOT NULL DEFAULT 'None',
  `matTexture6` varchar(32) NOT NULL DEFAULT 'None',
  `matTexture7` varchar(32) NOT NULL DEFAULT 'None',
  `matTexture8` varchar(32) NOT NULL DEFAULT 'None',
  `matTexture9` varchar(32) NOT NULL DEFAULT 'None',
  `matTexture10` varchar(32) NOT NULL,
  `matTexture11` varchar(32) NOT NULL DEFAULT 'None',
  `matTexture12` varchar(32) NOT NULL DEFAULT 'None',
  `matTexture13` varchar(32) NOT NULL DEFAULT 'None',
  `matTexture14` varchar(32) NOT NULL DEFAULT 'None'
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COLLATE=latin1_swedish_ci;

--
-- Dumping data for table `furniture`
--

INSERT INTO `furniture` (`id`, `propertydbid`, `modelid`, `name`, `price`, `type`, `pos_x`, `pos_y`, `pos_z`, `rot_x`, `rot_y`, `rot_z`, `interior`, `world`, `door_opened`, `door_locked`, `matModel0`, `matModel1`, `matModel2`, `matModel3`, `matModel4`, `matModel5`, `matModel6`, `matModel7`, `matModel8`, `matModel9`, `matModel10`, `matModel11`, `matModel12`, `matModel13`, `matModel14`, `matTxd0`, `matTxd1`, `matTxd2`, `matTxd3`, `matTxd4`, `matTxd5`, `matTxd6`, `matTxd7`, `matTxd8`, `matTxd9`, `matTxd10`, `matTxd11`, `matTxd12`, `matTxd13`, `matTxd14`, `matTexture0`, `matTexture1`, `matTexture2`, `matTexture3`, `matTexture4`, `matTexture5`, `matTexture6`, `matTexture7`, `matTexture8`, `matTexture9`, `matTexture10`, `matTexture11`, `matTexture12`, `matTexture13`, `matTexture14`) VALUES
(82, 42, 19379, 'Wall Static', 0, 1, 330.005, 458.411, 996.813, 0, 90, 0, 8, 38926, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(83, 42, 19449, 'Wall Static', 0, 1, 334.523, 448.788, 998.619, 0, -0.000007, 180, 8, 38926, 0, 0, 14792, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'ab_vgsgymbits01', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'bbar_wall2', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(84, 42, 19379, 'Wall Static', 0, 1, 330.005, 448.791, 1000.44, 0, 90, 0, 8, 38926, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(85, 42, 19379, 'Wall Static', 0, 1, 330.005, 458.411, 1000.44, 0, 90, 0, 8, 38926, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(86, 42, 19449, 'Wall Static', 0, 1, 334.523, 458.408, 998.619, 0, -0.000007, 180, 8, 38926, 0, 0, 14792, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'ab_vgsgymbits01', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'bbar_wall2', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(87, 42, 19449, 'Wall Static', 0, 1, 324.834, 458.407, 998.619, 0, 0, 180, 8, 38926, 0, 0, 14792, 14792, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'ab_vgsgymbits01', 'ab_vgsgymbits01', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'bbar_wall2', 'bbar_wall2', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(88, 42, 19449, 'Wall Static', 0, 1, 324.834, 448.788, 998.619, 0, 0, 180, 8, 38926, 0, 0, 14792, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'ab_vgsgymbits01', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'bbar_wall2', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(89, 42, 19379, 'Wall Static', 0, 1, 330.005, 448.791, 996.813, 0, 90, 0, 8, 38926, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(90, 42, 19449, 'Wall Static', 0, 1, 329.734, 463.137, 998.619, 0, 0, 270, 8, 38926, 0, 0, 14792, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'ab_vgsgymbits01', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'bbar_wall2', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(91, 42, 19449, 'Wall Static', 0, 1, 329.734, 444.058, 998.619, 0, 0, 270, 8, 38926, 0, 0, 14792, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'ab_vgsgymbits01', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'bbar_wall2', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(92, 42, 19802, 'Door Static', 0, 1, 328.981, 463.07, 996.899, 0, 0, 360, 8, 38926, 0, 0, 19486, 19486, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'burgalrystore_sfse', 'burgalrystore_sfse', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'Bow_LoadingBayDoor', 'Bow_LoadingBayDoor', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(93, 42, 2261, 'Golden gate frame', 1400, 0, 333.912, 456.243, 998.899, 0, 0, -91.0886, 8, 38926, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(94, 43, 19449, 'Wall Static', 0, 1, 334.523, 458.408, 998.619, 0, -0.000007, 180, 8, 12217, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(95, 43, 19379, 'Wall Static', 0, 1, 330.005, 458.411, 996.813, 0, 90, 0, 8, 12217, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(96, 43, 19379, 'Wall Static', 0, 1, 330.005, 448.791, 996.813, 0, 90, 0, 8, 12217, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(97, 43, 19379, 'Wall Static', 0, 1, 330.005, 458.411, 1000.44, 0, 90, 0, 8, 12217, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(98, 43, 19379, 'Wall Static', 0, 1, 330.005, 448.791, 1000.44, 0, 90, 0, 8, 12217, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(99, 43, 19449, 'Wall Static', 0, 1, 334.523, 448.788, 998.619, 0, -0.000007, 180, 8, 12217, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(100, 43, 19449, 'Wall Static', 0, 1, 324.834, 448.788, 998.619, 0, 0, 180, 8, 12217, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(101, 43, 19449, 'Wall Static', 0, 1, 324.834, 458.407, 998.619, 0, 0, 180, 8, 12217, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(102, 43, 19802, 'Door Static', 0, 1, 328.981, 463.07, 996.899, 0, 0, 360, 8, 12217, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(103, 43, 19449, 'Wall Static', 0, 1, 329.734, 444.058, 998.619, 0, 0, 270, 8, 12217, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(104, 43, 19449, 'Wall Static', 0, 1, 329.734, 463.137, 998.619, 0, 0, 270, 8, 12217, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(105, 44, 19379, 'Wall Static', 0, 1, 239.575, 458.411, 996.813, 0, 90, 0, 5, 34706, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(106, 44, 19449, 'Wall Static', 0, 1, 239.144, 453.848, 998.619, 0, 0, 90, 5, 34706, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(107, 44, 19379, 'Wall Static', 0, 1, 239.575, 458.411, 1000.43, 0, 90, 0, 5, 34706, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(108, 44, 19449, 'Wall Static', 0, 1, 239.144, 463.237, 998.619, 0, 0, 90, 5, 34706, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(109, 44, 19802, 'Door Static', 0, 1, 238.361, 463.17, 996.899, 0, 0, 360, 5, 34706, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(110, 44, 19449, 'Wall Static', 0, 1, 234.434, 458.408, 998.619, 0, 0, 180, 5, 34706, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(111, 44, 19449, 'Wall Static', 0, 1, 244.034, 458.408, 998.619, 0, 0, 180, 5, 34706, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(112, 45, 19802, 'Door Static', 0, 1, 238.361, 463.17, 996.899, 0, 0, 360, 5, 8850, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(113, 45, 19379, 'Wall Static', 0, 1, 239.575, 458.411, 996.813, 0, 90, 0, 5, 8850, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(114, 45, 19449, 'Wall Static', 0, 1, 239.144, 453.848, 998.619, 0, 0, 90, 5, 8850, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(115, 45, 19449, 'Wall Static', 0, 1, 244.034, 458.408, 998.619, 0, 0, 180, 5, 8850, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(116, 45, 19449, 'Wall Static', 0, 1, 239.144, 463.237, 998.619, 0, 0, 90, 5, 8850, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(117, 45, 19379, 'Wall Static', 0, 1, 239.575, 458.411, 1000.43, 0, 90, 0, 5, 8850, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(118, 45, 19449, 'Wall Static', 0, 1, 234.434, 458.408, 998.619, 0, 0, 180, 5, 8850, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(119, 46, 19379, 'Wall Static', 0, 1, 239.575, 458.411, 996.813, 0, 90, 0, 5, 14672, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(120, 46, 19449, 'Wall Static', 0, 1, 239.144, 453.848, 998.619, 0, 0, 90, 5, 14672, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(121, 46, 19379, 'Wall Static', 0, 1, 239.575, 458.411, 1000.43, 0, 90, 0, 5, 14672, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(122, 46, 19449, 'Wall Static', 0, 1, 239.144, 463.237, 998.619, 0, 0, 90, 5, 14672, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(123, 46, 19449, 'Wall Static', 0, 1, 244.034, 458.408, 998.619, 0, 0, 180, 5, 14672, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(124, 46, 19449, 'Wall Static', 0, 1, 234.434, 458.408, 998.619, 0, 0, 180, 5, 14672, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(125, 46, 19802, 'Door Static', 0, 1, 238.361, 463.17, 996.899, 0, 0, 360, 5, 14672, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(126, 47, 19379, 'Wall Static', 0, 1, 239.575, 458.411, 996.813, 0, 90, 0, 5, 36876, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(127, 47, 19379, 'Wall Static', 0, 1, 239.575, 458.411, 1000.43, 0, 90, 0, 5, 36876, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(128, 47, 19449, 'Wall Static', 0, 1, 239.144, 453.848, 998.619, 0, 0, 90, 5, 36876, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(129, 47, 19449, 'Wall Static', 0, 1, 234.434, 458.408, 998.619, 0, 0, 180, 5, 36876, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(130, 47, 19449, 'Wall Static', 0, 1, 244.034, 458.408, 998.619, 0, 0, 180, 5, 36876, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(131, 47, 19449, 'Wall Static', 0, 1, 239.144, 463.237, 998.619, 0, 0, 90, 5, 36876, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(132, 47, 19802, 'Door Static', 0, 1, 238.361, 463.17, 996.899, 0, 0, 360, 5, 36876, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(133, 48, 19449, 'Wall Static', 0, 1, 239.144, 453.848, 998.619, 0, 0, 90, 5, 34955, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(134, 48, 19379, 'Wall Static', 0, 1, 239.575, 458.411, 996.813, 0, 90, 0, 5, 34955, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(135, 48, 19379, 'Wall Static', 0, 1, 239.575, 458.411, 1000.43, 0, 90, 0, 5, 34955, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(136, 48, 19449, 'Wall Static', 0, 1, 244.034, 458.408, 998.619, 0, 0, 180, 5, 34955, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(137, 48, 19449, 'Wall Static', 0, 1, 234.434, 458.408, 998.619, 0, 0, 180, 5, 34955, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(138, 48, 19449, 'Wall Static', 0, 1, 239.144, 463.237, 998.619, 0, 0, 90, 5, 34955, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(139, 48, 19802, 'Door Static', 0, 1, 238.361, 463.17, 996.899, 0, 0, 360, 5, 34955, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(140, 49, 19379, 'Wall Static', 0, 1, 239.575, 458.411, 996.813, 0, 90, 0, 5, 22099, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(141, 49, 19379, 'Wall Static', 0, 1, 239.575, 458.411, 1000.43, 0, 90, 0, 5, 22099, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(142, 49, 19449, 'Wall Static', 0, 1, 244.034, 458.408, 998.619, 0, 0, 180, 5, 22099, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(143, 49, 19449, 'Wall Static', 0, 1, 239.144, 453.848, 998.619, 0, 0, 90, 5, 22099, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(144, 49, 19449, 'Wall Static', 0, 1, 239.144, 463.237, 998.619, 0, 0, 90, 5, 22099, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(145, 49, 19802, 'Door Static', 0, 1, 238.361, 463.17, 996.899, 0, 0, 360, 5, 22099, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(146, 49, 19449, 'Wall Static', 0, 1, 234.434, 458.408, 998.619, 0, 0, 180, 5, 22099, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(147, 50, 19379, 'Wall Static', 0, 1, 239.575, 458.411, 996.813, 0, 90, 0, 5, 24778, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(148, 50, 19449, 'Wall Static', 0, 1, 239.144, 453.848, 998.619, 0, 0, 90, 5, 24778, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(149, 50, 19379, 'Wall Static', 0, 1, 239.575, 458.411, 1000.43, 0, 90, 0, 5, 24778, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(150, 50, 19449, 'Wall Static', 0, 1, 244.034, 458.408, 998.619, 0, 0, 180, 5, 24778, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(151, 50, 19449, 'Wall Static', 0, 1, 239.144, 463.237, 998.619, 0, 0, 90, 5, 24778, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(152, 50, 19449, 'Wall Static', 0, 1, 234.434, 458.408, 998.619, 0, 0, 180, 5, 24778, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(153, 50, 19802, 'Door Static', 0, 1, 238.361, 463.17, 996.899, 0, 0, 360, 5, 24778, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(154, 51, 19379, 'Wall Static', 0, 1, 239.575, 458.411, 1000.43, 0, 90, 0, 5, 15852, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(155, 51, 19449, 'Wall Static', 0, 1, 239.144, 453.848, 998.619, 0, 0, 90, 5, 15852, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(156, 51, 19379, 'Wall Static', 0, 1, 239.575, 458.411, 996.813, 0, 90, 0, 5, 15852, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(157, 51, 19449, 'Wall Static', 0, 1, 244.034, 458.408, 998.619, 0, 0, 180, 5, 15852, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(158, 51, 19449, 'Wall Static', 0, 1, 234.434, 458.408, 998.619, 0, 0, 180, 5, 15852, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(159, 51, 19449, 'Wall Static', 0, 1, 239.144, 463.237, 998.619, 0, 0, 90, 5, 15852, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(160, 51, 19802, 'Door Static', 0, 1, 238.361, 463.17, 996.899, 0, 0, 360, 5, 15852, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(161, 52, 19379, 'Wall Static', 0, 1, 239.575, 458.411, 996.813, 0, 90, 0, 5, 27941, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(162, 52, 19449, 'Wall Static', 0, 1, 244.034, 458.408, 998.619, 0, 0, 180, 5, 27941, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(163, 52, 19449, 'Wall Static', 0, 1, 234.434, 458.408, 998.619, 0, 0, 180, 5, 27941, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(164, 52, 19449, 'Wall Static', 0, 1, 239.144, 463.237, 998.619, 0, 0, 90, 5, 27941, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(165, 52, 19379, 'Wall Static', 0, 1, 239.575, 458.411, 1000.43, 0, 90, 0, 5, 27941, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(166, 52, 19449, 'Wall Static', 0, 1, 239.144, 453.848, 998.619, 0, 0, 90, 5, 27941, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(167, 52, 19802, 'Door Static', 0, 1, 238.361, 463.17, 996.899, 0, 0, 360, 5, 27941, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(168, 53, 19379, 'Wall Static', 0, 1, 239.575, 458.411, 996.813, 0, 90, 0, 5, 33138, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(169, 53, 19449, 'Wall Static', 0, 1, 239.144, 453.848, 998.619, 0, 0, 90, 5, 33138, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(170, 53, 19379, 'Wall Static', 0, 1, 239.575, 458.411, 1000.43, 0, 90, 0, 5, 33138, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(171, 53, 19449, 'Wall Static', 0, 1, 244.034, 458.408, 998.619, 0, 0, 180, 5, 33138, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(172, 53, 19449, 'Wall Static', 0, 1, 239.144, 463.237, 998.619, 0, 0, 90, 5, 33138, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(173, 53, 19449, 'Wall Static', 0, 1, 234.434, 458.408, 998.619, 0, 0, 180, 5, 33138, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(174, 53, 19802, 'Door Static', 0, 1, 238.361, 463.17, 996.899, 0, 0, 360, 5, 33138, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(175, 54, 19379, 'Wall Static', 0, 1, 239.575, 458.411, 996.813, 0, 90, 0, 5, 16685, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(176, 54, 19449, 'Wall Static', 0, 1, 239.144, 453.848, 998.619, 0, 0, 90, 5, 16685, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(177, 54, 19449, 'Wall Static', 0, 1, 239.144, 463.237, 998.619, 0, 0, 90, 5, 16685, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(178, 54, 19449, 'Wall Static', 0, 1, 234.434, 458.408, 998.619, 0, 0, 180, 5, 16685, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(179, 54, 19449, 'Wall Static', 0, 1, 244.034, 458.408, 998.619, 0, 0, 180, 5, 16685, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(180, 54, 19379, 'Wall Static', 0, 1, 239.575, 458.411, 1000.43, 0, 90, 0, 5, 16685, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(181, 54, 19802, 'Door Static', 0, 1, 238.361, 463.17, 996.899, 0, 0, 360, 5, 16685, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(182, 55, 19379, 'Wall Static', 0, 1, 239.575, 458.411, 996.813, 0, 90, 0, 5, 36724, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(183, 55, 19802, 'Door Static', 0, 1, 238.361, 463.17, 996.899, 0, 0, 360, 5, 36724, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(184, 55, 19449, 'Wall Static', 0, 1, 239.144, 463.237, 998.619, 0, 0, 90, 5, 36724, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(185, 55, 19449, 'Wall Static', 0, 1, 234.434, 458.408, 998.619, 0, 0, 180, 5, 36724, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(186, 55, 19379, 'Wall Static', 0, 1, 239.575, 458.411, 1000.43, 0, 90, 0, 5, 36724, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(187, 55, 19449, 'Wall Static', 0, 1, 239.144, 453.848, 998.619, 0, 0, 90, 5, 36724, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(188, 55, 19449, 'Wall Static', 0, 1, 244.034, 458.408, 998.619, 0, 0, 180, 5, 36724, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(189, 56, 19379, 'Wall Static', 0, 1, 239.575, 458.411, 996.813, 0, 90, 0, 5, 23887, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(190, 56, 19379, 'Wall Static', 0, 1, 239.575, 458.411, 1000.43, 0, 90, 0, 5, 23887, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(191, 56, 19449, 'Wall Static', 0, 1, 239.144, 453.848, 998.619, 0, 0, 90, 5, 23887, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(192, 56, 19449, 'Wall Static', 0, 1, 239.144, 463.237, 998.619, 0, 0, 90, 5, 23887, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(193, 56, 19449, 'Wall Static', 0, 1, 234.434, 458.408, 998.619, 0, 0, 180, 5, 23887, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(194, 56, 19449, 'Wall Static', 0, 1, 244.034, 458.408, 998.619, 0, 0, 180, 5, 23887, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(195, 56, 19802, 'Door Static', 0, 1, 238.361, 463.17, 996.899, 0, 0, 360, 5, 23887, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(196, 57, 19379, 'Wall Static', 0, 1, 239.575, 458.411, 996.813, 0, 90, 0, 5, 9631, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(197, 57, 19449, 'Wall Static', 0, 1, 239.144, 453.848, 998.619, 0, 0, 90, 5, 9631, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(198, 57, 19449, 'Wall Static', 0, 1, 239.144, 463.237, 998.619, 0, 0, 90, 5, 9631, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(199, 57, 19449, 'Wall Static', 0, 1, 234.434, 458.408, 998.619, 0, 0, 180, 5, 9631, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(200, 57, 19802, 'Door Static', 0, 1, 238.361, 463.17, 996.899, 0, 0, 360, 5, 9631, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(201, 57, 19449, 'Wall Static', 0, 1, 244.034, 458.408, 998.619, 0, 0, 180, 5, 9631, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(202, 57, 19379, 'Wall Static', 0, 1, 239.575, 458.411, 1000.43, 0, 90, 0, 5, 9631, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(203, 58, 19449, 'Wall Static', 0, 1, 239.144, 453.848, 998.619, 0, 0, 90, 5, 4635, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(204, 58, 19379, 'Wall Static', 0, 1, 239.575, 458.411, 996.813, 0, 90, 0, 5, 4635, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(205, 58, 19379, 'Wall Static', 0, 1, 239.575, 458.411, 1000.43, 0, 90, 0, 5, 4635, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(206, 58, 19449, 'Wall Static', 0, 1, 239.144, 463.237, 998.619, 0, 0, 90, 5, 4635, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(207, 58, 19449, 'Wall Static', 0, 1, 234.434, 458.408, 998.619, 0, 0, 180, 5, 4635, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(208, 58, 19449, 'Wall Static', 0, 1, 244.034, 458.408, 998.619, 0, 0, 180, 5, 4635, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(209, 58, 19802, 'Door Static', 0, 1, 238.361, 463.17, 996.899, 0, 0, 360, 5, 4635, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(210, 59, 19379, 'Wall Static', 0, 1, 239.575, 458.411, 996.813, 0, 90, 0, 5, 23603, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(211, 59, 19449, 'Wall Static', 0, 1, 239.144, 453.848, 998.619, 0, 0, 90, 5, 23603, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(212, 59, 19379, 'Wall Static', 0, 1, 239.575, 458.411, 1000.43, 0, 90, 0, 5, 23603, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(213, 59, 19449, 'Wall Static', 0, 1, 244.034, 458.408, 998.619, 0, 0, 180, 5, 23603, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(214, 59, 19449, 'Wall Static', 0, 1, 239.144, 463.237, 998.619, 0, 0, 90, 5, 23603, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None');
INSERT INTO `furniture` (`id`, `propertydbid`, `modelid`, `name`, `price`, `type`, `pos_x`, `pos_y`, `pos_z`, `rot_x`, `rot_y`, `rot_z`, `interior`, `world`, `door_opened`, `door_locked`, `matModel0`, `matModel1`, `matModel2`, `matModel3`, `matModel4`, `matModel5`, `matModel6`, `matModel7`, `matModel8`, `matModel9`, `matModel10`, `matModel11`, `matModel12`, `matModel13`, `matModel14`, `matTxd0`, `matTxd1`, `matTxd2`, `matTxd3`, `matTxd4`, `matTxd5`, `matTxd6`, `matTxd7`, `matTxd8`, `matTxd9`, `matTxd10`, `matTxd11`, `matTxd12`, `matTxd13`, `matTxd14`, `matTexture0`, `matTexture1`, `matTexture2`, `matTexture3`, `matTexture4`, `matTexture5`, `matTexture6`, `matTexture7`, `matTexture8`, `matTexture9`, `matTexture10`, `matTexture11`, `matTexture12`, `matTexture13`, `matTexture14`) VALUES
(215, 59, 19449, 'Wall Static', 0, 1, 234.434, 458.408, 998.619, 0, 0, 180, 5, 23603, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(216, 59, 19802, 'Door Static', 0, 1, 238.361, 463.17, 996.899, 0, 0, 360, 5, 23603, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(217, 60, 19379, 'Wall Static', 0, 1, 239.575, 458.411, 996.813, 0, 90, 0, 5, 25612, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(218, 60, 19449, 'Wall Static', 0, 1, 239.144, 453.848, 998.619, 0, 0, 90, 5, 25612, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(219, 60, 19379, 'Wall Static', 0, 1, 239.575, 458.411, 1000.43, 0, 90, 0, 5, 25612, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(220, 60, 19449, 'Wall Static', 0, 1, 244.034, 458.408, 998.619, 0, 0, 180, 5, 25612, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(221, 60, 19449, 'Wall Static', 0, 1, 239.144, 463.237, 998.619, 0, 0, 90, 5, 25612, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(222, 60, 19802, 'Door Static', 0, 1, 238.361, 463.17, 996.899, 0, 0, 360, 5, 25612, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(223, 60, 19449, 'Wall Static', 0, 1, 234.434, 458.408, 998.619, 0, 0, 180, 5, 25612, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(224, 61, 19379, 'Wall Static', 0, 1, 239.575, 458.411, 996.813, 0, 90, 0, 5, 23174, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(225, 61, 19449, 'Wall Static', 0, 1, 239.144, 453.848, 998.619, 0, 0, 90, 5, 23174, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(226, 61, 19379, 'Wall Static', 0, 1, 239.575, 458.411, 1000.43, 0, 90, 0, 5, 23174, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(227, 61, 19449, 'Wall Static', 0, 1, 239.144, 463.237, 998.619, 0, 0, 90, 5, 23174, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(228, 61, 19802, 'Door Static', 0, 1, 238.361, 463.17, 996.899, 0, 0, 360, 5, 23174, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(229, 61, 19449, 'Wall Static', 0, 1, 234.434, 458.408, 998.619, 0, 0, 180, 5, 23174, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(230, 61, 19449, 'Wall Static', 0, 1, 244.034, 458.408, 998.619, 0, 0, 180, 5, 23174, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(231, 62, 19449, 'Wall Static', 0, 1, 234.434, 458.408, 998.619, 0, 0, 180, 5, 4726, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(232, 62, 19449, 'Wall Static', 0, 1, 239.144, 453.848, 998.619, 0, 0, 90, 5, 4726, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(233, 62, 19802, 'Door Static', 0, 1, 238.361, 463.17, 996.899, 0, 0, 360, 5, 4726, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(234, 62, 19379, 'Wall Static', 0, 1, 239.575, 458.411, 996.813, 0, 90, 0, 5, 4726, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(235, 62, 19379, 'Wall Static', 0, 1, 239.575, 458.411, 1000.43, 0, 90, 0, 5, 4726, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(236, 62, 19449, 'Wall Static', 0, 1, 244.034, 458.408, 998.619, 0, 0, 180, 5, 4726, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(237, 62, 19449, 'Wall Static', 0, 1, 239.144, 463.237, 998.619, 0, 0, 90, 5, 4726, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(238, 63, 19379, 'Wall Static', 0, 1, 239.575, 458.411, 996.813, 0, 90, 0, 5, 31782, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(239, 63, 19449, 'Wall Static', 0, 1, 239.144, 453.848, 998.619, 0, 0, 90, 5, 31782, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(240, 63, 19449, 'Wall Static', 0, 1, 244.034, 458.408, 998.619, 0, 0, 180, 5, 31782, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(241, 63, 19379, 'Wall Static', 0, 1, 239.575, 458.411, 1000.43, 0, 90, 0, 5, 31782, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(242, 63, 19449, 'Wall Static', 0, 1, 239.144, 463.237, 998.619, 0, 0, 90, 5, 31782, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(243, 63, 19449, 'Wall Static', 0, 1, 234.434, 458.408, 998.619, 0, 0, 180, 5, 31782, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(244, 63, 19802, 'Door Static', 0, 1, 238.361, 463.17, 996.899, 0, 0, 360, 5, 31782, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(245, 64, 19379, 'Wall Static', 0, 1, 239.575, 458.411, 996.813, 0, 90, 0, 5, 24396, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(246, 64, 19449, 'Wall Static', 0, 1, 239.144, 453.848, 998.619, 0, 0, 90, 5, 24396, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(247, 64, 19802, 'Door Static', 0, 1, 238.361, 463.17, 996.899, 0, 0, 360, 5, 24396, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(248, 64, 19449, 'Wall Static', 0, 1, 239.144, 463.237, 998.619, 0, 0, 90, 5, 24396, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(249, 64, 19449, 'Wall Static', 0, 1, 244.034, 458.408, 998.619, 0, 0, 180, 5, 24396, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(250, 64, 19449, 'Wall Static', 0, 1, 234.434, 458.408, 998.619, 0, 0, 180, 5, 24396, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(251, 64, 19379, 'Wall Static', 0, 1, 239.575, 458.411, 1000.43, 0, 90, 0, 5, 24396, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(252, 65, 19379, 'Wall Static', 0, 1, 239.575, 458.411, 996.813, 0, 90, 0, 5, 20388, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(253, 65, 19449, 'Wall Static', 0, 1, 239.144, 453.848, 998.619, 0, 0, 90, 5, 20388, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(254, 65, 19379, 'Wall Static', 0, 1, 239.575, 458.411, 1000.43, 0, 90, 0, 5, 20388, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(255, 65, 19449, 'Wall Static', 0, 1, 244.034, 458.408, 998.619, 0, 0, 180, 5, 20388, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(256, 65, 19449, 'Wall Static', 0, 1, 239.144, 463.237, 998.619, 0, 0, 90, 5, 20388, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(257, 65, 19449, 'Wall Static', 0, 1, 234.434, 458.408, 998.619, 0, 0, 180, 5, 20388, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(258, 65, 19802, 'Door Static', 0, 1, 238.361, 463.17, 996.899, 0, 0, 360, 5, 20388, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(259, 66, 19379, 'Wall Static', 0, 1, 239.575, 458.411, 996.813, 0, 90, 0, 5, 26940, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(260, 66, 19449, 'Wall Static', 0, 1, 239.144, 453.848, 998.619, 0, 0, 90, 5, 26940, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(261, 66, 19379, 'Wall Static', 0, 1, 239.575, 458.411, 1000.43, 0, 90, 0, 5, 26940, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(262, 66, 19449, 'Wall Static', 0, 1, 244.034, 458.408, 998.619, 0, 0, 180, 5, 26940, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(263, 66, 19449, 'Wall Static', 0, 1, 234.434, 458.408, 998.619, 0, 0, 180, 5, 26940, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(264, 66, 19449, 'Wall Static', 0, 1, 239.144, 463.237, 998.619, 0, 0, 90, 5, 26940, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(265, 66, 19802, 'Door Static', 0, 1, 238.361, 463.17, 996.899, 0, 0, 360, 5, 26940, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(266, 67, 19379, 'Wall Static', 0, 1, 239.575, 458.411, 996.813, 0, 90, 0, 5, 16491, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(267, 67, 19449, 'Wall Static', 0, 1, 239.144, 453.848, 998.619, 0, 0, 90, 5, 16491, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(268, 67, 19379, 'Wall Static', 0, 1, 239.575, 458.411, 1000.43, 0, 90, 0, 5, 16491, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(269, 67, 19449, 'Wall Static', 0, 1, 234.434, 458.408, 998.619, 0, 0, 180, 5, 16491, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(270, 67, 19449, 'Wall Static', 0, 1, 239.144, 463.237, 998.619, 0, 0, 90, 5, 16491, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(271, 67, 19449, 'Wall Static', 0, 1, 244.034, 458.408, 998.619, 0, 0, 180, 5, 16491, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(272, 67, 19802, 'Door Static', 0, 1, 238.361, 463.17, 996.899, 0, 0, 360, 5, 16491, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(273, 68, 19379, 'Wall Static', 0, 1, 239.575, 458.411, 996.813, 0, 90, 0, 5, 14694, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(274, 68, 19379, 'Wall Static', 0, 1, 239.575, 458.411, 1000.43, 0, 90, 0, 5, 14694, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(275, 68, 19449, 'Wall Static', 0, 1, 244.034, 458.408, 998.619, 0, 0, 180, 5, 14694, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(276, 68, 19449, 'Wall Static', 0, 1, 239.144, 453.848, 998.619, 0, 0, 90, 5, 14694, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(277, 68, 19802, 'Door Static', 0, 1, 238.361, 463.17, 996.899, 0, 0, 360, 5, 14694, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(278, 68, 19449, 'Wall Static', 0, 1, 234.434, 458.408, 998.619, 0, 0, 180, 5, 14694, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(279, 68, 19449, 'Wall Static', 0, 1, 239.144, 463.237, 998.619, 0, 0, 90, 5, 14694, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(280, 69, 19379, 'Wall Static', 0, 1, 239.575, 458.411, 996.813, 0, 90, 0, 5, 14993, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(281, 69, 19449, 'Wall Static', 0, 1, 239.144, 453.848, 998.619, 0, 0, 90, 5, 14993, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(282, 69, 19379, 'Wall Static', 0, 1, 239.575, 458.411, 1000.43, 0, 90, 0, 5, 14993, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(283, 69, 19449, 'Wall Static', 0, 1, 239.144, 463.237, 998.619, 0, 0, 90, 5, 14993, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(284, 69, 19449, 'Wall Static', 0, 1, 234.434, 458.408, 998.619, 0, 0, 180, 5, 14993, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(285, 69, 19802, 'Door Static', 0, 1, 238.361, 463.17, 996.899, 0, 0, 360, 5, 14993, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(286, 69, 19449, 'Wall Static', 0, 1, 244.034, 458.408, 998.619, 0, 0, 180, 5, 14993, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(287, 70, 19379, 'Wall Static', 0, 1, 239.575, 458.411, 996.813, 0, 90, 0, 5, 24055, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(288, 70, 19449, 'Wall Static', 0, 1, 239.144, 453.848, 998.619, 0, 0, 90, 5, 24055, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(289, 70, 19449, 'Wall Static', 0, 1, 244.034, 458.408, 998.619, 0, 0, 180, 5, 24055, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(290, 70, 19379, 'Wall Static', 0, 1, 239.575, 458.411, 1000.43, 0, 90, 0, 5, 24055, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(291, 70, 19449, 'Wall Static', 0, 1, 239.144, 463.237, 998.619, 0, 0, 90, 5, 24055, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(292, 70, 19802, 'Door Static', 0, 1, 238.361, 463.17, 996.899, 0, 0, 360, 5, 24055, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(293, 70, 19449, 'Wall Static', 0, 1, 234.434, 458.408, 998.619, 0, 0, 180, 5, 24055, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(294, 71, 19379, 'Wall Static', 0, 1, 239.575, 458.411, 996.813, 0, 90, 0, 5, 37601, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(295, 71, 19449, 'Wall Static', 0, 1, 239.144, 453.848, 998.619, 0, 0, 90, 5, 37601, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(296, 71, 19379, 'Wall Static', 0, 1, 239.575, 458.411, 1000.43, 0, 90, 0, 5, 37601, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(297, 71, 19449, 'Wall Static', 0, 1, 244.034, 458.408, 998.619, 0, 0, 180, 5, 37601, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(298, 71, 19449, 'Wall Static', 0, 1, 239.144, 463.237, 998.619, 0, 0, 90, 5, 37601, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(299, 71, 19449, 'Wall Static', 0, 1, 234.434, 458.408, 998.619, 0, 0, 180, 5, 37601, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(300, 71, 19802, 'Door Static', 0, 1, 238.361, 463.17, 996.899, 0, 0, 360, 5, 37601, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(301, 72, 19379, 'Wall Static', 0, 1, 239.575, 458.411, 996.813, 0, 90, 0, 5, 25438, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(302, 72, 19379, 'Wall Static', 0, 1, 239.575, 458.411, 1000.43, 0, 90, 0, 5, 25438, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(303, 72, 19449, 'Wall Static', 0, 1, 239.144, 453.848, 998.619, 0, 0, 90, 5, 25438, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(304, 72, 19449, 'Wall Static', 0, 1, 239.144, 463.237, 998.619, 0, 0, 90, 5, 25438, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(305, 72, 19449, 'Wall Static', 0, 1, 244.034, 458.408, 998.619, 0, 0, 180, 5, 25438, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(306, 72, 19802, 'Door Static', 0, 1, 238.361, 463.17, 996.899, 0, 0, 360, 5, 25438, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(307, 72, 19449, 'Wall Static', 0, 1, 234.434, 458.408, 998.619, 0, 0, 180, 5, 25438, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(308, 73, 19379, 'Wall Static', 0, 1, 239.575, 458.411, 996.813, 0, 90, 0, 5, 12987, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(309, 73, 19449, 'Wall Static', 0, 1, 239.144, 453.848, 998.619, 0, 0, 90, 5, 12987, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(310, 73, 19379, 'Wall Static', 0, 1, 239.575, 458.411, 1000.43, 0, 90, 0, 5, 12987, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(311, 73, 19449, 'Wall Static', 0, 1, 244.034, 458.408, 998.619, 0, 0, 180, 5, 12987, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(312, 73, 19449, 'Wall Static', 0, 1, 239.144, 463.237, 998.619, 0, 0, 90, 5, 12987, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(313, 73, 19449, 'Wall Static', 0, 1, 234.434, 458.408, 998.619, 0, 0, 180, 5, 12987, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(314, 73, 19802, 'Door Static', 0, 1, 238.361, 463.17, 996.899, 0, 0, 360, 5, 12987, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(315, 74, 19379, 'Wall Static', 0, 1, 239.575, 458.411, 996.813, 0, 90, 0, 5, 25044, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(316, 74, 19449, 'Wall Static', 0, 1, 239.144, 453.848, 998.619, 0, 0, 90, 5, 25044, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(317, 74, 19379, 'Wall Static', 0, 1, 239.575, 458.411, 1000.43, 0, 90, 0, 5, 25044, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(318, 74, 19449, 'Wall Static', 0, 1, 244.034, 458.408, 998.619, 0, 0, 180, 5, 25044, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(319, 74, 19449, 'Wall Static', 0, 1, 239.144, 463.237, 998.619, 0, 0, 90, 5, 25044, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(320, 74, 19802, 'Door Static', 0, 1, 238.361, 463.17, 996.899, 0, 0, 360, 5, 25044, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(321, 74, 19449, 'Wall Static', 0, 1, 234.434, 458.408, 998.619, 0, 0, 180, 5, 25044, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(322, 75, 19379, 'Wall Static', 0, 1, 239.575, 458.411, 996.813, 0, 90, 0, 5, 5936, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(323, 75, 19449, 'Wall Static', 0, 1, 234.434, 458.408, 998.619, 0, 0, 180, 5, 5936, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(324, 75, 19379, 'Wall Static', 0, 1, 239.575, 458.411, 1000.43, 0, 90, 0, 5, 5936, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(325, 75, 19449, 'Wall Static', 0, 1, 244.034, 458.408, 998.619, 0, 0, 180, 5, 5936, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(326, 75, 19449, 'Wall Static', 0, 1, 239.144, 463.237, 998.619, 0, 0, 90, 5, 5936, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(327, 75, 19802, 'Door Static', 0, 1, 238.361, 463.17, 996.899, 0, 0, 360, 5, 5936, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(328, 75, 19449, 'Wall Static', 0, 1, 239.144, 453.848, 998.619, 0, 0, 90, 5, 5936, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(329, 76, 19379, 'Wall Static', 0, 1, 239.575, 458.411, 996.813, 0, 90, 0, 5, 20126, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(330, 76, 19379, 'Wall Static', 0, 1, 239.575, 458.411, 1000.43, 0, 90, 0, 5, 20126, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(331, 76, 19449, 'Wall Static', 0, 1, 234.434, 458.408, 998.619, 0, 0, 180, 5, 20126, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(332, 76, 19449, 'Wall Static', 0, 1, 239.144, 453.848, 998.619, 0, 0, 90, 5, 20126, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(333, 76, 19449, 'Wall Static', 0, 1, 244.034, 458.408, 998.619, 0, 0, 180, 5, 20126, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(334, 76, 19802, 'Door Static', 0, 1, 238.361, 463.17, 996.899, 0, 0, 360, 5, 20126, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(335, 76, 19449, 'Wall Static', 0, 1, 239.144, 463.237, 998.619, 0, 0, 90, 5, 20126, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(336, 77, 19379, 'Wall Static', 0, 1, 239.575, 458.411, 996.813, 0, 90, 0, 5, 33241, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(337, 77, 19449, 'Wall Static', 0, 1, 239.144, 453.848, 998.619, 0, 0, 90, 5, 33241, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(338, 77, 19379, 'Wall Static', 0, 1, 239.575, 458.411, 1000.43, 0, 90, 0, 5, 33241, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(339, 77, 19449, 'Wall Static', 0, 1, 244.034, 458.408, 998.619, 0, 0, 180, 5, 33241, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(340, 77, 19802, 'Door Static', 0, 1, 238.361, 463.17, 996.899, 0, 0, 360, 5, 33241, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(341, 77, 19449, 'Wall Static', 0, 1, 239.144, 463.237, 998.619, 0, 0, 90, 5, 33241, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(342, 77, 19449, 'Wall Static', 0, 1, 234.434, 458.408, 998.619, 0, 0, 180, 5, 33241, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(343, 78, 19379, 'Wall Static', 0, 1, 239.575, 458.411, 996.813, 0, 90, 0, 5, 1661, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(344, 78, 19449, 'Wall Static', 0, 1, 239.144, 453.848, 998.619, 0, 0, 90, 5, 1661, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(345, 78, 19449, 'Wall Static', 0, 1, 244.034, 458.408, 998.619, 0, 0, 180, 5, 1661, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(346, 78, 19802, 'Door Static', 0, 1, 238.361, 463.17, 996.899, 0, 0, 360, 5, 1661, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(347, 78, 19379, 'Wall Static', 0, 1, 239.575, 458.411, 1000.43, 0, 90, 0, 5, 1661, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(348, 78, 19449, 'Wall Static', 0, 1, 239.144, 463.237, 998.619, 0, 0, 90, 5, 1661, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None');
INSERT INTO `furniture` (`id`, `propertydbid`, `modelid`, `name`, `price`, `type`, `pos_x`, `pos_y`, `pos_z`, `rot_x`, `rot_y`, `rot_z`, `interior`, `world`, `door_opened`, `door_locked`, `matModel0`, `matModel1`, `matModel2`, `matModel3`, `matModel4`, `matModel5`, `matModel6`, `matModel7`, `matModel8`, `matModel9`, `matModel10`, `matModel11`, `matModel12`, `matModel13`, `matModel14`, `matTxd0`, `matTxd1`, `matTxd2`, `matTxd3`, `matTxd4`, `matTxd5`, `matTxd6`, `matTxd7`, `matTxd8`, `matTxd9`, `matTxd10`, `matTxd11`, `matTxd12`, `matTxd13`, `matTxd14`, `matTexture0`, `matTexture1`, `matTexture2`, `matTexture3`, `matTexture4`, `matTexture5`, `matTexture6`, `matTexture7`, `matTexture8`, `matTexture9`, `matTexture10`, `matTexture11`, `matTexture12`, `matTexture13`, `matTexture14`) VALUES
(349, 78, 19449, 'Wall Static', 0, 1, 234.434, 458.408, 998.619, 0, 0, 180, 5, 1661, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(350, 79, 19379, 'Wall Static', 0, 1, 239.575, 458.411, 996.813, 0, 90, 0, 5, 30267, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(351, 79, 19449, 'Wall Static', 0, 1, 239.144, 453.848, 998.619, 0, 0, 90, 5, 30267, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(352, 79, 19379, 'Wall Static', 0, 1, 239.575, 458.411, 1000.43, 0, 90, 0, 5, 30267, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(353, 79, 19449, 'Wall Static', 0, 1, 244.034, 458.408, 998.619, 0, 0, 180, 5, 30267, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(354, 79, 19802, 'Door Static', 0, 1, 238.361, 463.17, 996.899, 0, 0, 360, 5, 30267, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(355, 79, 19449, 'Wall Static', 0, 1, 234.434, 458.408, 998.619, 0, 0, 180, 5, 30267, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(356, 79, 19449, 'Wall Static', 0, 1, 239.144, 463.237, 998.619, 0, 0, 90, 5, 30267, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(357, 80, 19379, 'Wall Static', 0, 1, 239.575, 458.411, 996.813, 0, 90, 0, 5, 25615, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(358, 80, 19379, 'Wall Static', 0, 1, 239.575, 458.411, 1000.43, 0, 90, 0, 5, 25615, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(359, 80, 19449, 'Wall Static', 0, 1, 239.144, 453.848, 998.619, 0, 0, 90, 5, 25615, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(360, 80, 19449, 'Wall Static', 0, 1, 244.034, 458.408, 998.619, 0, 0, 180, 5, 25615, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(361, 80, 19449, 'Wall Static', 0, 1, 239.144, 463.237, 998.619, 0, 0, 90, 5, 25615, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(362, 80, 19802, 'Door Static', 0, 1, 238.361, 463.17, 996.899, 0, 0, 360, 5, 25615, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(363, 80, 19449, 'Wall Static', 0, 1, 234.434, 458.408, 998.619, 0, 0, 180, 5, 25615, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(364, 81, 19379, 'Wall Static', 0, 1, 239.575, 458.411, 996.813, 0, 90, 0, 5, 21490, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(365, 81, 19449, 'Wall Static', 0, 1, 239.144, 453.848, 998.619, 0, 0, 90, 5, 21490, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(366, 81, 19379, 'Wall Static', 0, 1, 239.575, 458.411, 1000.43, 0, 90, 0, 5, 21490, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(367, 81, 19449, 'Wall Static', 0, 1, 239.144, 463.237, 998.619, 0, 0, 90, 5, 21490, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(368, 81, 19802, 'Door Static', 0, 1, 238.361, 463.17, 996.899, 0, 0, 360, 5, 21490, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(369, 81, 19449, 'Wall Static', 0, 1, 234.434, 458.408, 998.619, 0, 0, 180, 5, 21490, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(370, 81, 19449, 'Wall Static', 0, 1, 244.034, 458.408, 998.619, 0, 0, 180, 5, 21490, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(371, 82, 19379, 'Wall Static', 0, 1, 239.575, 458.411, 996.813, 0, 90, 0, 5, 12219, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(372, 82, 19379, 'Wall Static', 0, 1, 239.575, 458.411, 1000.43, 0, 90, 0, 5, 12219, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(373, 82, 19449, 'Wall Static', 0, 1, 239.144, 463.237, 998.619, 0, 0, 90, 5, 12219, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(374, 82, 19802, 'Door Static', 0, 1, 238.361, 463.17, 996.899, 0, 0, 360, 5, 12219, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(375, 82, 19449, 'Wall Static', 0, 1, 239.144, 453.848, 998.619, 0, 0, 90, 5, 12219, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(376, 82, 19449, 'Wall Static', 0, 1, 244.034, 458.408, 998.619, 0, 0, 180, 5, 12219, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(377, 82, 19449, 'Wall Static', 0, 1, 234.434, 458.408, 998.619, 0, 0, 180, 5, 12219, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(378, 83, 19379, 'Wall Static', 0, 1, 239.575, 458.411, 996.813, 0, 90, 0, 5, 39328, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(379, 83, 19449, 'Wall Static', 0, 1, 244.034, 458.408, 998.619, 0, 0, 180, 5, 39328, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(380, 83, 19449, 'Wall Static', 0, 1, 239.144, 453.848, 998.619, 0, 0, 90, 5, 39328, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(381, 83, 19449, 'Wall Static', 0, 1, 239.144, 463.237, 998.619, 0, 0, 90, 5, 39328, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(382, 83, 19449, 'Wall Static', 0, 1, 234.434, 458.408, 998.619, 0, 0, 180, 5, 39328, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(383, 83, 19802, 'Door Static', 0, 1, 238.361, 463.17, 996.899, 0, 0, 360, 5, 39328, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(384, 83, 19379, 'Wall Static', 0, 1, 239.575, 458.411, 1000.43, 0, 90, 0, 5, 39328, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(385, 84, 19379, 'Wall Static', 0, 1, 239.575, 458.411, 996.813, 0, 90, 0, 5, 15032, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(386, 84, 19379, 'Wall Static', 0, 1, 239.575, 458.411, 1000.43, 0, 90, 0, 5, 15032, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(387, 84, 19449, 'Wall Static', 0, 1, 239.144, 453.848, 998.619, 0, 0, 90, 5, 15032, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(388, 84, 19449, 'Wall Static', 0, 1, 239.144, 463.237, 998.619, 0, 0, 90, 5, 15032, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(389, 84, 19449, 'Wall Static', 0, 1, 244.034, 458.408, 998.619, 0, 0, 180, 5, 15032, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(390, 84, 19449, 'Wall Static', 0, 1, 234.434, 458.408, 998.619, 0, 0, 180, 5, 15032, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(391, 84, 19802, 'Door Static', 0, 1, 238.361, 463.17, 996.899, 0, 0, 360, 5, 15032, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(392, 85, 19379, 'Wall Static', 0, 1, 239.575, 458.411, 996.813, 0, 90, 0, 5, 27278, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(393, 85, 19449, 'Wall Static', 0, 1, 239.144, 453.848, 998.619, 0, 0, 90, 5, 27278, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(394, 85, 19379, 'Wall Static', 0, 1, 239.575, 458.411, 1000.43, 0, 90, 0, 5, 27278, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(395, 85, 19449, 'Wall Static', 0, 1, 244.034, 458.408, 998.619, 0, 0, 180, 5, 27278, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(396, 85, 19449, 'Wall Static', 0, 1, 239.144, 463.237, 998.619, 0, 0, 90, 5, 27278, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(397, 85, 19449, 'Wall Static', 0, 1, 234.434, 458.408, 998.619, 0, 0, 180, 5, 27278, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(398, 85, 19802, 'Door Static', 0, 1, 238.361, 463.17, 996.899, 0, 0, 360, 5, 27278, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(399, 86, 19379, 'Wall Static', 0, 1, 239.575, 458.411, 996.813, 0, 90, 0, 5, 16240, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(400, 86, 19449, 'Wall Static', 0, 1, 244.034, 458.408, 998.619, 0, 0, 180, 5, 16240, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(401, 86, 19449, 'Wall Static', 0, 1, 239.144, 463.237, 998.619, 0, 0, 90, 5, 16240, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(402, 86, 19379, 'Wall Static', 0, 1, 239.575, 458.411, 1000.43, 0, 90, 0, 5, 16240, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(403, 86, 19449, 'Wall Static', 0, 1, 239.144, 453.848, 998.619, 0, 0, 90, 5, 16240, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(404, 86, 19802, 'Door Static', 0, 1, 238.361, 463.17, 996.899, 0, 0, 360, 5, 16240, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(405, 86, 19449, 'Wall Static', 0, 1, 234.434, 458.408, 998.619, 0, 0, 180, 5, 16240, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(406, 87, 19379, 'Wall Static', 0, 1, 239.575, 458.411, 996.813, 0, 90, 0, 5, 9108, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(407, 87, 19449, 'Wall Static', 0, 1, 244.034, 458.408, 998.619, 0, 0, 180, 5, 9108, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(408, 87, 19449, 'Wall Static', 0, 1, 239.144, 453.848, 998.619, 0, 0, 90, 5, 9108, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(409, 87, 19449, 'Wall Static', 0, 1, 239.144, 463.237, 998.619, 0, 0, 90, 5, 9108, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(410, 87, 19802, 'Door Static', 0, 1, 238.361, 463.17, 996.899, 0, 0, 360, 5, 9108, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(411, 87, 19379, 'Wall Static', 0, 1, 239.575, 458.411, 1000.43, 0, 90, 0, 5, 9108, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(412, 87, 19449, 'Wall Static', 0, 1, 234.434, 458.408, 998.619, 0, 0, 180, 5, 9108, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(413, 88, 19449, 'Wall Static', 0, 1, 239.144, 453.848, 998.619, 0, 0, 90, 5, 5585, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(414, 88, 19379, 'Wall Static', 0, 1, 239.575, 458.411, 1000.43, 0, 90, 0, 5, 5585, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(415, 88, 19449, 'Wall Static', 0, 1, 244.034, 458.408, 998.619, 0, 0, 180, 5, 5585, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(416, 88, 19379, 'Wall Static', 0, 1, 239.575, 458.411, 996.813, 0, 90, 0, 5, 5585, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(417, 88, 19449, 'Wall Static', 0, 1, 234.434, 458.408, 998.619, 0, 0, 180, 5, 5585, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(418, 88, 19802, 'Door Static', 0, 1, 238.361, 463.17, 996.899, 0, 0, 360, 5, 5585, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(419, 88, 19449, 'Wall Static', 0, 1, 239.144, 463.237, 998.619, 0, 0, 90, 5, 5585, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(421, 88, 11720, 'Red double bed', 5000, 0, 243.035, 455.39, 996.898, 0, 0, -176.786, 5, 5585, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(422, 88, 2841, 'Round green rug', 250, 0, 242.362, 456.897, 997.009, 0, 0, -1.59856, 5, 5585, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(423, 88, 11706, 'Wastebin', 1000, 0, 241.864, 454.255, 996.989, 0, 0, -175.702, 5, 5585, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(424, 88, 19356, 'wall004', 1400, 0, 240.127, 455.529, 998.629, 0, 0, -178.548, 5, 5585, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None');

-- --------------------------------------------------------

--
-- Table structure for table `gates`
--

CREATE TABLE `gates` (
  `dbid` int(11) NOT NULL,
  `modelid` int(11) NOT NULL DEFAULT 0,
  `interior` int(11) NOT NULL DEFAULT 0,
  `world` int(11) NOT NULL DEFAULT 0,
  `faction` int(11) NOT NULL DEFAULT 0,
  `status` int(11) NOT NULL DEFAULT 0,
  `posx` float NOT NULL DEFAULT 0,
  `posy` float NOT NULL DEFAULT 0,
  `posz` float NOT NULL DEFAULT 0,
  `posrx` float NOT NULL DEFAULT 0,
  `posry` float NOT NULL DEFAULT 0,
  `posrz` float NOT NULL DEFAULT 0,
  `movex` float NOT NULL DEFAULT 0,
  `movey` float NOT NULL DEFAULT 0,
  `movez` float NOT NULL DEFAULT 0,
  `moverx` float NOT NULL DEFAULT 0,
  `movery` float NOT NULL DEFAULT 0,
  `moverz` float NOT NULL DEFAULT 0
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `gates`
--

INSERT INTO `gates` (`dbid`, `modelid`, `interior`, `world`, `faction`, `status`, `posx`, `posy`, `posz`, `posrx`, `posry`, `posrz`, `movex`, `movey`, `movez`, `moverx`, `movery`, `moverz`) VALUES
(21, 968, 0, 0, 2, 0, 1544.71, -1630.78, 12.9628, -3.8999, -88.4999, -89.6406, 1544.71, -1630.78, 12.9628, -3.8999, -0.8999, -89.6406);

-- --------------------------------------------------------

--
-- Table structure for table `inventory`
--

CREATE TABLE `inventory` (
  `ID` int(12) DEFAULT 0,
  `invID` int(12) NOT NULL,
  `invItem` varchar(32) DEFAULT NULL,
  `invModel` int(12) DEFAULT 0,
  `invQuantity` int(12) DEFAULT 0,
  `invType` int(12) DEFAULT 0
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COLLATE=latin1_swedish_ci;

--
-- Dumping data for table `inventory`
--

INSERT INTO `inventory` (`ID`, `invID`, `invItem`, `invModel`, `invQuantity`, `invType`) VALUES
(61, 874, 'Fish Bait', 19566, 4954, 0),
(61, 875, 'Repair Kits', 1650, 1, 0),
(61, 877, 'Fishing Rod', 18632, 1, 0),
(61, 881, 'Spraycan', 365, 1, 0),
(61, 892, 'Cellphone', 18867, 1, 0),
(61, 893, 'Radio', 19942, 1, 0),
(61, 894, 'Gascan', 1650, 1, 0),
(61, 895, 'Spike Bat', -2200, 1, 0),
(131, 908, 'Radio', 19942, 1, 0),
(131, 909, 'Cellphone', 18867, 1, 0),
(131, 910, 'Gascan', 1650, 5, 0),
(131, 911, 'Repair Kits', 1650, 1, 0),
(92, 948, 'Spike Bat', 2045, 1, 0),
(60, 959, 'Regular Ammo', 2040, 34, 0),
(60, 1006, 'Shotgun', 348, 1, 0),
(61, 1013, 'Pisswasher', 1484, 1, 0),
(138, 1015, 'Baking Soda', 19570, 1, 0),
(138, 1016, 'Radio', 19942, 1, 0),
(138, 1017, 'Cellphone', 18867, 1, 0),
(138, 1018, 'Screwdriver', 18644, 1, 0),
(1, 1030, 'Fishing Rod', 18632, 1, 0),
(138, 1040, 'Fishing Rod', 18632, 1, 0),
(138, 1041, 'Fish Bait', 19566, 6, 0),
(71, 1051, 'Pisswasher', 1486, 3, 0),
(65, 1052, 'Screwdriver', 18644, 1, 0),
(146, 1061, 'Cellphone', 18867, 1, 0),
(146, 1062, 'Radio', 19942, 1, 0),
(146, 1063, 'Screwdriver', 18644, 1, 0),
(146, 1064, 'Pisswasher', 1484, 1, 0),
(1, 1068, 'Screwdriver', 18644, 1, 0),
(84, 1070, 'Screwdriver', 18644, 1, 0),
(1, 1071, 'Desert Eagle', 348, 1, 0),
(84, 1074, 'Colt 45', 346, 1, 0),
(84, 1075, 'Surplus Ammo', 2040, 27, 0),
(1, 1076, 'Shotgun', 349, 1, 0),
(84, 1077, 'Desert Eagle', 348, 1, 0),
(80, 1081, 'Fishing Rod', 18632, 2, 0),
(148, 1091, 'Cellphone', 18867, 1, 0),
(80, 1092, 'Cellphone', 18867, 1, 0),
(80, 1093, 'Radio', 19942, 1, 0),
(148, 1094, 'Radio', 19942, 1, 0),
(61, 1095, 'Screwdriver', 18644, 1, 0),
(80, 1096, 'Carp', 19630, 8, 0),
(80, 1097, 'Cod', 19630, 4, 0),
(80, 1098, 'Salmon', 19630, 5, 0),
(80, 1099, 'Cat Fish', 19630, 2, 0),
(78, 1100, 'Fishing Rod', 18632, 1, 0),
(78, 1101, 'Fish Bait', 19566, 4, 0),
(65, 1107, 'Cellphone', 18867, 1, 0),
(65, 1108, 'Raw Meat', 19582, 1, 0),
(65, 1109, 'Repair Kits', 1650, 1, 0),
(65, 1110, 'Gascan', 1650, 1, 0);

-- --------------------------------------------------------

--
-- Table structure for table `kick_logs`
--

CREATE TABLE `kick_logs` (
  `id` int(11) NOT NULL,
  `KickedDBID` int(11) NOT NULL,
  `KickedName` varchar(32) NOT NULL,
  `Reason` varchar(128) NOT NULL,
  `KickedBy` varchar(32) NOT NULL,
  `Date` varchar(90) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COLLATE=latin1_swedish_ci;

--
-- Dumping data for table `kick_logs`
--

INSERT INTO `kick_logs` (`id`, `KickedDBID`, `KickedName`, `Reason`, `KickedBy`, `Date`) VALUES
(4, 1, 'Charles Morgan', 'Relog pak malah jadi CJ', 'Jayvon Williams', 'December 7, 2024 17:10:43'),
(5, 1, 'Omar Epps', 'bug CJ', 'Jayvon Williams', 'December 7, 2024 17:26:41'),
(6, 1, 'Quincy Brentwood', 'afk', 'Jayvon Williams', 'December 7, 2024 17:27:47'),
(7, 61, 'Ornelle Adarrion', 'relog lagi', 'Charles Morgan', 'December 8, 2024 08:59:30'),
(8, 61, 'Quintrell Adarrion', 'tes', 'Charles Morgan', 'December 8, 2024 09:25:41'),
(9, 61, 'Charles Morgan', 'tes', 'Charles Morgan', 'December 8, 2024 09:25:46'),
(10, 61, 'Charles Morgan', 'BUG MULU NGENTOTTTTTTT', 'Charles Morgan', 'December 8, 2024 09:27:22'),
(11, 60, 'Giovanna Rodriguez', 'timestuck', 'Giovanna Rodriguez', 'December 22, 2024 19:49:19'),
(12, 78, 'Brayn Conwell', 'timestuck', 'Brayn Conwell', 'December 22, 2024 19:49:53');

-- --------------------------------------------------------

--
-- Table structure for table `logs`
--

CREATE TABLE `logs` (
  `type` varchar(512) NOT NULL DEFAULT 'none',
  `name` varchar(512) NOT NULL DEFAULT 'none',
  `result` varchar(512) NOT NULL DEFAULT 'none',
  `ID` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `logs`
--

INSERT INTO `logs` (`type`, `name`, `result`, `ID`) VALUES
('Logs Advertise', 'Jayvon Williams', '[SELL] Sultan bet', 0);

-- --------------------------------------------------------

--
-- Table structure for table `masters`
--

CREATE TABLE `masters` (
  `acc_dbid` int(11) NOT NULL,
  `acc_name` varchar(32) NOT NULL DEFAULT 'None',
  `acc_pass` varchar(128) NOT NULL DEFAULT 'None',
  `acc_admin` int(11) NOT NULL DEFAULT 0,
  `secret_word` int(11) NOT NULL DEFAULT 0,
  `forum_name` varchar(60) NOT NULL DEFAULT 'Null',
  `register_date` varchar(90) NOT NULL DEFAULT 'None',
  `register_ip` varchar(60) NOT NULL DEFAULT 'None',
  `active_ip` varchar(60) NOT NULL DEFAULT 'None',
  `verified` int(11) NOT NULL DEFAULT 0,
  `discord` varchar(128) NOT NULL DEFAULT '0',
  `vip` int(11) NOT NULL DEFAULT 0,
  `vip_time` int(11) NOT NULL DEFAULT 0,
  `street_credits` int(11) NOT NULL DEFAULT 0
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COLLATE=latin1_swedish_ci;

--
-- Dumping data for table `masters`
--

INSERT INTO `masters` (`acc_dbid`, `acc_name`, `acc_pass`, `acc_admin`, `secret_word`, `forum_name`, `register_date`, `register_ip`, `active_ip`, `verified`, `discord`, `vip`, `vip_time`, `street_credits`) VALUES
(18, 'Radeetz', '051bb6ea0a45dbf11e4bbce3c21141678b10be9d', 4, 0, 'Radeetz', 'February 12, 2024 19:46:10', '127.0.0.1', '127.0.0.1', 1, '706433548797607957', 3, 0, 0),
(60, 'Blixkyyy', '051bb6ea0a45dbf11e4bbce3c21141678b10be9d', 4, 0, 'None', 'May 2, 2024 13:04:40', '127.0.0.1', '103.147.9.108', 1, '0', 0, 0, 0),
(113, 'dookie', '143c0fedcee3b4cc880d4e208198d4c17e920325', 0, 0, 'Null', 'None', 'None', '110.136.222.94', 0, '896331681684934666', 0, 0, 0),
(114, 'ghivin', 'd16dbbb318838bd6c664a19e34769664bb01218c', 1, 0, 'Null', 'None', 'None', '103.163.36.86', 0, '1221090597922668640', 0, 0, 0),
(115, 'imo_string', '72c7ae91c13844b7bc18fca978401ddc1d59522d', 0, 0, 'Null', 'None', 'None', '36.83.23.172', 0, '1266792195835433061', 0, 0, 0),
(116, 'Bavallgo', 'af47b43f16f2cd0b4066446c12d93abc58c0e4dd', 0, 0, 'Null', 'None', 'None', '180.253.188.114', 0, '968294643831832626', 0, 0, 0),
(117, 'Juliannn', 'b93dbe7c711c45d5ea4e5f0dbdba1bb0a6498f4a', 0, 0, 'Null', 'None', 'None', '172.18.0.6', 0, '1281977325289869315', 0, 0, 0),
(118, 'frengki', '009d1920c2f16814d44842c5d4578894ce38810f', 0, 0, 'Null', 'None', 'None', '180.252.89.83', 0, '1155905161097650276', 0, 0, 0),
(119, 'nwjns', '6a48e3e95e86e87c1f916f469bef94192477864c', 0, 0, 'Null', 'None', 'None', '172.18.0.6', 0, '521230350345830411', 0, 0, 0),
(120, 'DaylonT', '2c43abf019b2954a3366351f3875a27f28950f57', 0, 0, 'Null', 'None', 'None', '114.10.156.197', 0, '695096579610116209', 0, 0, 0),
(121, 'notubidev', 'ac9328b5ed3c4fd903d2069206f6ab784173b3ad', 2, 0, 'Null', 'None', 'None', '125.167.56.147', 0, '736195609983451207', 0, 0, 0),
(122, 'Droppes', '48c91ef491a644e73aa05fb31cfeb1052be2a856', 0, 0, 'Null', 'None', 'None', '180.253.186.161', 0, '1067361148929835018', 0, 0, 0),
(123, 'graceee', 'b6f7d2d3c51da187043c60f3a01b672a39c870e7', 0, 0, 'Null', 'None', 'None', '114.122.15.193', 0, '1217017167531216918', 0, 0, 0),
(124, 'Brugiel', '225dbeced259880368fef223e4cb9572260d2bb0', 0, 0, 'Null', 'None', 'None', '140.213.161.120', 0, '1294663994518278205', 0, 0, 0),
(125, 'mikelo', '0cd4048abf0efa5beaf6760a202b1a920e8b8057', 0, 0, 'Null', 'None', 'None', '114.10.103.206', 0, '1155881842310914079', 0, 0, 0),
(126, 'Jackie', '5a51bfdcbeed6a562a1a1d15a0ceb4f15bab2ae2', 0, 0, 'Null', 'None', 'None', '172.18.0.6', 0, '908742149321949276', 0, 0, 0),
(127, 'genitals', '960814d45f13d37b5e0e3e2900afa94e8635b82b', 2, 0, 'Null', 'None', 'None', '180.252.175.173', 0, '418319343663841282', 0, 0, 0),
(128, 'Christy', '72d456ac4acc7d7ba0efc7a615adeffd7ba6fa18', 0, 0, 'Null', 'None', 'None', '103.108.31.88', 0, '908931695460360213', 0, 0, 0),
(129, 'siwode', '7c4a8d09ca3762af61e59520943dc26494f8941b', 0, 0, 'Null', 'None', 'None', '172.18.0.6', 0, '1067127645814390826', 0, 0, 0),
(130, 'starz', '0f3bb48c805c9437cf22bc91ff41e17f88648e2b', 0, 0, 'Null', 'None', 'None', '103.47.133.28', 0, '852373316332159016', 0, 0, 0),
(131, 'Charlie', '13b66dfbbc6f41676d5364dc0cb9aff370dfe46f', 3, 0, 'Null', 'None', 'None', '160.22.222.19', 0, '939495459255361557', 1, 0, 0),
(132, 'Etooo', '11584a74f9fb79f9fed4a2eb8e79de99d58b4a4e', 0, 0, 'Null', 'None', 'None', '172.18.0.6', 0, '1182239931804958800', 0, 0, 0),
(133, 'ruztol', '23a7b6332dacc00911bb6c914e7ed282aed82531', 0, 0, 'Null', 'None', 'None', '203.78.117.186', 0, '1089619978040389804', 0, 0, 0),
(134, 'Hobigtasa', '8cfcd428135c54fb6221866302d93c1481171bd8', 0, 0, 'Null', 'None', 'None', '180.242.215.194', 0, '735510172000321567', 0, 0, 0),
(135, 'whackt', 'de6bf3c770dbb703566bafe459a45fd1eac3f232', 0, 0, 'Null', 'None', 'None', '103.138.49.7', 0, '815823433652240405', 0, 0, 0),
(136, 'essencey', '9e50036b8d0ed79d7e42819d93ac3239677c8cf4', 0, 0, 'Null', 'None', 'None', '172.18.0.6', 0, '1228321057782628513', 0, 0, 0),
(137, 'Repandeve', '18858cca9638d78c97fa58e3fa9367c8ac4718c4', 0, 0, 'Null', 'None', 'None', '172.18.0.6', 0, '1127541429649027183', 0, 0, 0),
(138, 'JhonAndreas', '79439744ddea20374df86a11d3d37fcffce9542e', 0, 0, 'Null', 'None', 'None', '140.213.49.39', 0, '1033954340244828200', 0, 0, 0),
(139, 'Martabak', 'a8188afc82f4de497bf0df197fc550e4dda20a26', 0, 0, 'Null', 'None', 'None', '180.244.167.28', 0, '762141229731282946', 0, 0, 0),
(140, 'Cockup', 'a4372b3d53d94840957050f60f4ccc44b3b97118', 0, 0, 'Null', 'None', 'None', '114.10.157.150', 0, '926075740821291118', 0, 0, 0),
(141, 'randz', '3d08e20a7e08bb56dd4ea91c885eb6523d6571cf', 1, 0, 'a', 'None', 'None', '180.249.203.59', 0, '1073413566922764341', 0, 0, 0),
(142, 'Joozxc', '7080a1acd6ec0a934ce201b81beed4468e80182c', 0, 0, 'Null', 'None', 'None', '36.85.216.24', 0, '987645270290468894', 0, 0, 0),
(143, 'stranger', '63874dc52157ed05e334cd82584cb7791a1370d5', 0, 0, 'Null', 'None', 'None', '114.10.149.192', 0, '572377785771753493', 0, 0, 0),
(144, 'chooo', '9fb96dd493cf7a9d4ca3accfab7252ce8ad5f520', 0, 0, 'Null', 'None', 'None', '114.122.198.105', 0, '465207140131405834', 0, 0, 0),
(145, 'Brian1605', 'e688e3fae086cddc8f67f94ddff4de2221a87c5e', 0, 0, 'Null', 'None', 'None', '180.253.185.137', 0, '1239483008776540208', 0, 0, 0),
(146, 'ghaisendra', 'a1bad23264a4202cdb834c5b599f48eeabc273d1', 0, 0, 'Null', 'None', 'None', '104.28.215.133', 0, '1131541271941480579', 0, 0, 0),
(147, 'busst', 'ee66b2ffc52e56459bbee602d8cd1afd7c394731', 0, 0, 'Null', 'None', 'None', '172.18.0.25', 0, '1190649593352945727', 0, 0, 0),
(148, 'Xenzy', 'fb364449105296ef873c72006337ea272beb8b57', 0, 0, 'Null', 'None', 'None', '104.28.159.172', 0, '863773581183680543', 0, 0, 0),
(149, 'walkins', 'd4d3a4c9466e1f74061125f9135bb66007e65225', 0, 0, 'Null', 'None', 'None', '172.18.0.25', 0, '1077238790223057117', 0, 0, 0),
(150, 'sweaat', '84c02cf1a5c61809a974711b8fdcf092910033ca', 0, 0, 'Null', 'None', 'None', '114.198.244.11', 0, '1167823863829233734', 0, 0, 0),
(151, 'LaputaNZ', '0749f52831bf5df69c2f9ce6802d2e7ee56f6f53', 0, 0, 'Null', 'None', 'None', '182.3.47.228', 0, '1054381778149847061', 0, 0, 0),
(152, 'aylaz', 'de6bf3c770dbb703566bafe459a45fd1eac3f232', 0, 0, 'Null', 'None', 'None', '172.18.0.25', 0, '740489550228488193', 0, 0, 0),
(153, 'Sigma', 'c51a7d4312110627624c46c66475fa267533ad18', 0, 0, 'Null', 'None', 'None', '180.249.203.59', 0, '1113453248863535134', 0, 0, 0),
(154, 'Hezxy', '49a75a1f3881e8b75457dfc2b44b7ccb31a28b7e', 0, 0, 'Null', 'None', 'None', '172.18.0.25', 0, '333737533584310274', 0, 0, 0),
(155, 'anocc', 'a9c0e5422d1eb7a6b4dcda5f50f4cd2ca7e53c88', 0, 0, 'Null', 'None', 'None', '180.242.143.64', 0, '1231874249216495678', 0, 0, 0),
(156, 'hcm07', '5880bb84dadfd2318acfd5a520255cd2466465ac', 0, 0, 'Null', 'None', 'None', '172.18.0.25', 0, '969813392607027221', 0, 0, 0),
(157, 'podka', 'c86baee69691e009b49a585984030ab9eaa7cc21', 0, 0, 'Null', 'None', 'None', '114.10.101.65', 0, '1185761402128957511', 0, 0, 0),
(158, 'popmie', '2661d4352b88be8c137e4c154754e914d3abc8b7', 0, 0, 'Null', 'None', 'None', '172.18.0.25', 0, '967039709874384896', 0, 0, 0),
(159, 'RyanRifonzo', '0fa86f32e2874ad95a20d74d399a0faf9210457c', 0, 0, 'Null', 'None', 'None', '172.18.0.25', 0, '805268471020519445', 0, 0, 0),
(160, 'Mohammed_Ray', 'cd537f97d748f7f26dfd00e386e352c1936b77c8', 0, 0, 'Null', 'None', 'None', '172.18.0.25', 0, '1247819889444519957', 0, 0, 0),
(161, 'malayboyswag', '85d66f812679117d56cc04188474f35761e6dda5', 0, 0, 'Null', 'None', 'None', '103.189.201.189', 0, '1268562175325241406', 0, 0, 0),
(162, 'nazelaenak', 'f7ea82c4a0f9e177314b3dd68b2da6c8aa89d0af', 0, 0, 'Null', 'None', 'None', '139.0.141.125', 0, '1301887892368527442', 0, 0, 0),
(163, 'Danzzzz', 'c1566b26250f74b18d40612d5e79eacbe6f00119', 0, 0, 'Null', 'None', 'None', '114.122.101.33', 0, '1009748549094887425', 0, 0, 0),
(164, 'Dandol', '3e9586f4c6d914a75e07d10d0295dc5893ec9492', 0, 0, 'Null', 'None', 'None', '172.18.0.25', 0, '924524857172033536', 0, 0, 0),
(165, 'lilgrclaa', 'c77e9010b6321d98192c7d204bd7f12b04eabf48', 0, 0, 'Null', 'None', 'None', '172.18.0.25', 0, '991258071701659739', 0, 0, 0),
(166, 'ojerasy', '8513768157bf59475018a510aa79f5c2cef7ccde', 0, 0, 'Null', 'None', 'None', '172.18.0.25', 0, '1156521958742179890', 0, 0, 0),
(167, 'Guhsc', '957d8326631b3abd6fa51e37e3c2cc03c7d0b4d6', 0, 0, 'Null', 'None', 'None', '172.18.0.25', 0, '1265638875749945426', 0, 0, 0),
(168, 'lippoo', '4c8897c01c65caa547e66f087d7b7b2c1905c44c', 0, 0, 'Null', 'None', 'None', '172.18.0.25', 0, '690070248459730976', 0, 0, 0),
(169, 'glxko', '2763a6d2fe4f2ae4203647f1d51e2301dfac7091', 0, 0, 'Null', 'None', 'None', '180.254.166.5', 0, '922658788421562419', 0, 0, 0),
(170, 'Parque', '244e6f11c753574877b465a5231e29683f432190', 0, 0, 'Null', 'None', 'None', '172.18.0.25', 0, '979290656390381618', 0, 0, 0),
(171, 'bogrek', '0cd8eb3bb8e080b5f2d4c37dc019320e901e0f56', 0, 0, 'Null', 'None', 'None', '172.18.0.25', 0, '1172443755765305424', 0, 0, 0),
(172, 'Sofarr', 'a6c97a390d20e3b32c3a97940e1197e814a350c3', 0, 0, 'Null', 'None', 'None', '172.18.0.25', 0, '1215593023363354655', 0, 0, 0),
(173, 'loops', 'dd73e99c69d9e42573bc20fd7977ad33aa9d94f5', 0, 0, 'Null', 'None', 'None', '172.18.0.25', 0, '1113074090446700575', 0, 0, 0),
(174, 'Cyhna', '30661220de82799498f26dc0330f0677be39ea4e', 0, 0, 'Null', 'None', 'None', '125.164.21.198', 0, '732806574677950514', 0, 0, 0),
(175, 'antoslayer', 'a3294b4cfcba1ee0dff6f3302f12f80dbccecaa9', 0, 0, 'Null', 'None', 'None', '104.28.163.27', 0, '951334031847456828', 0, 0, 0),
(176, 'HannB', 'b49729d443b6a14576390d2f153728789b986e60', 0, 0, 'Null', 'None', 'None', '103.175.229.237', 0, '1275053894304530504', 0, 0, 0),
(177, 'levian', '8b1c1faabe1788ef06d293ed5e3493feedc7380b', 0, 0, 'Null', 'None', 'None', '172.18.0.25', 0, '536157389666123776', 0, 0, 0),
(178, 'Blumners', '6ad59c524c6bd168d7bc500b0f86150ff7f6dafe', 0, 0, 'Null', 'None', 'None', '202.169.232.180', 0, '943774572799483995', 0, 0, 0),
(179, 'uppercut', 'd45a36b6079f6485b625eb2c1a4a3a9bb034ef17', 0, 0, 'Null', 'None', 'None', '172.18.0.25', 0, '1235176050011541625', 0, 0, 0),
(180, 'Kontol123', '6570eba43b72684955167550c5c7a41c71724534', 0, 0, 'Null', 'None', 'None', '172.18.0.25', 0, '849539374499627038', 0, 0, 0),
(181, 'AvahIyah', '547602547bbc97d192990cf75347eef0e849b78e', 0, 0, 'Null', 'None', 'None', '172.18.0.25', 0, '862644070031818762', 0, 0, 0),
(182, 'Maradorios', 'a6cc92b251a5c80bc45d72f44e462c1d26f491cb', 0, 0, 'Null', 'None', 'None', '182.4.198.254', 0, '1120181498054721556', 0, 0, 0),
(183, 'Ziorosa', '70d027347434c19d3e3c663aa12a4b2d8f6d38ac', 0, 0, 'Null', 'None', 'None', '172.18.0.5', 0, '1258718022370197565', 0, 0, 0),
(184, 'on3side', 'c53255317bb11707d0f614696b3ce6f221d0e2f2', 0, 0, 'Null', 'None', 'None', '172.18.0.5', 0, '1124101568548057118', 0, 0, 0),
(185, 'Youngtrey', '63c9b72f8e06fbae167930d97ddf949d9b8bf590', 0, 0, 'Null', 'None', 'None', '172.18.0.5', 0, '1240438970249121852', 0, 0, 0),
(186, 'palace', 'f38debc2fc1c0cb7362be2eb886f2697bc0567e8', 0, 0, 'Null', 'None', 'None', '172.18.0.5', 0, '1041102105202675833', 0, 0, 0),
(187, 'Ccasper', '6f11f917f84addfa39aa3710a7cad5264a4a502d', 0, 0, 'Null', 'None', 'None', '36.85.217.111', 0, '541820244021477377', 0, 0, 0),
(188, 'KillaMachina', 'b391beb7fd1c32f34e61dbeded9723f67a600713', 0, 0, 'Null', 'None', 'None', '125.164.150.201', 0, '463294249388081163', 0, 0, 0),
(189, 'rapha', 'e1c7e1d7c8467ef0e5c43a560b1b05645d06736f', 0, 0, 'Null', 'None', 'None', '110.138.93.29', 0, '858944243774914581', 0, 0, 0),
(190, 'eclypsn', '0803e0e8764fe9e90c8f24eaef5b8c714ef0100c', 0, 0, 'Null', 'None', 'None', '172.18.0.5', 0, '1283343357665476644', 0, 0, 0),
(191, 'babakbelur', '6cafadf0e5cad6d0c88b1793f76ebb133a52d0ee', 0, 0, 'Null', 'None', 'None', '180.251.244.33', 0, '1188351540835123240', 0, 0, 0),
(192, 'roxyy', 'c483b73869298271fab0edd5d4a7ac7ef3d46e1c', 0, 0, 'Null', 'None', 'None', '172.18.0.5', 0, '806900373142503434', 0, 0, 0),
(193, 'XenoX', 'c11e8e3cc4ebc137f7ccd9c65bcb1343db26db71', 0, 0, 'Null', 'None', 'None', '172.18.0.5', 0, '887808633717551195', 0, 0, 0),
(194, 'Abielfrl', '28e358e663130be6850249999278bdfbd535c1f3', 0, 0, 'Null', 'None', 'None', '172.18.0.5', 0, '702141774185103422', 0, 0, 0),
(195, 'seatboy', 'a71f86515ec867704476168736fc0a1679e739e4', 0, 0, 'Null', 'None', 'None', '172.18.0.5', 0, '567275549131538444', 0, 0, 0),
(196, 'Wanzz', 'efb52433858d8cda676cc1974464f443170fc149', 0, 0, 'Null', 'None', 'None', '172.18.0.5', 0, '1101555081532407829', 0, 0, 0),
(197, 'Kemaluan', '4e3f4dcc38c4fa42266663d0477b22d0872446ac', 0, 0, 'Null', 'None', 'None', '114.10.120.131', 0, '1145009493357383690', 0, 0, 0),
(198, 'crewsackan', 'c16aaa9589fd3c77ed4554a6209e14a676255ea2', 0, 0, 'Null', 'None', 'None', '172.18.0.5', 0, '756137221685248020', 0, 0, 0),
(199, 'kudanel', '607ed603a72a95e8b2242fdec39e53059a2922b2', 0, 0, 'Null', 'None', 'None', '182.2.52.114', 0, '1044531713533030401', 0, 0, 0),
(200, 'shisisan', 'c7fe1b87b498ef447d6c67ae6587a65273c9d2f4', 0, 0, 'Null', 'None', 'None', '172.18.0.5', 0, '1059388664225992737', 0, 0, 0),
(201, 'Jisoo', '9835c7952155d9ea05b0b48523efbd26e87168fb', 0, 0, 'Null', 'None', 'None', '172.18.0.5', 0, '1222420852050493462', 0, 0, 0),
(202, 'FromPluto', '79b0bc286ff9fd1dc02514c221c7916fe6297d33', 0, 0, 'Null', 'None', 'None', '223.25.110.217', 0, '889842670221029377', 0, 0, 0),
(203, 'Lynxx', '1b2a9601a481356c05c871385f9c90ab6cf746c7', 0, 0, 'Null', 'None', 'None', '172.18.0.5', 0, '712105477441454080', 0, 0, 0),
(204, 'watts', '00734ea769725e28fa10aadd8f930788d781081c', 0, 0, 'Null', 'None', 'None', '114.10.24.97', 0, '924118040856133652', 0, 0, 0),
(205, 'MABARGTA', '4f05e1b3ed9f4286bc95d11bf3fe5aae9aef0bf9', 0, 0, 'Null', 'None', 'None', '182.3.72.120', 0, '1229695462823428128', 0, 0, 0),
(206, 'ArmadiLo', 'e68d415204d652340e0bbcdc20695e37c8a408bb', 0, 0, 'Null', 'None', 'None', '172.18.0.5', 0, '1253558498080456724', 0, 0, 0),
(207, 'Ryonaldho', 'ca6f896d1291a3c30d0ab68cb79e067bb1ef2008', 0, 0, 'Null', 'None', 'None', '180.251.234.9', 0, '853068425370140702', 0, 0, 0),
(208, 'DamDmw', '91505556a3d9838c3a814cffea21dc7713f6e72b', 0, 0, 'Null', 'None', 'None', '114.125.47.165', 0, '360700542567055372', 0, 0, 0),
(209, 'Hammer', '5ac29aa226afcf5798ab5fda6e1d2567b2bc5f69', 0, 0, 'Null', 'None', 'None', '158.140.182.88', 0, '906776954122948660', 0, 0, 0),
(210, 'yOungbie', 'c34eda8f59861ad9c8c9207c5ce7aa5a43dc3cab', 0, 0, 'Null', 'None', 'None', '180.251.202.29', 0, '765223658544955392', 0, 0, 0),
(211, 'youton', '24e1bf4b752ef9ddc7932b8cec677cfab3c50993', 0, 0, 'Null', 'None', 'None', '140.213.103.227', 0, '731623686804733953', 0, 0, 0),
(212, 'irgiyy', '4a4d4d8f853dfa00a744aad567db84e4640fc0f0', 0, 0, 'Null', 'None', 'None', '172.18.0.5', 0, '1073562055338102875', 0, 0, 0),
(213, 'Pankeztone', '836de80d9c0c5ed19d5bffb598aa5b611d047507', 0, 0, 'Null', 'None', 'None', '182.2.51.201', 0, '786463609562988544', 0, 0, 0),
(214, 'yamoridixon', 'a60fa110c4e0eb4bbcbad96245ad2639bbe03a1b', 0, 0, 'Null', 'None', 'None', '180.242.194.250', 0, '1190661876120551534', 0, 0, 0),
(215, 'Starboyy', '6a95c7409d0146943d0391ab5186922d807b4f97', 0, 0, 'Null', 'None', 'None', '36.85.223.182', 0, '894512174721011712', 0, 0, 0),
(216, 'Salsaxy', '323438f61d43ff12ee055f973670cfab01f3604e', 0, 0, 'Null', 'None', 'None', '103.147.82.234', 0, '469960091307737099', 0, 0, 0),
(217, 'Abraham', 'f4c042740f5915c346cbc3bb1c61ce46bdf256d6', 0, 0, 'Null', 'None', 'None', '172.18.0.5', 0, '918440190194876417', 0, 0, 0),
(218, 'violentvira', '394040ca21e20ea7fdcd5b0dcf2221870fb0ca5a', 0, 0, 'Null', 'None', 'None', '114.10.44.81', 0, '696385718779641946', 0, 0, 0),
(219, 'berserk', '18de160c8a22d828b58d6398ec319e135e23816a', 0, 0, 'Null', 'None', 'None', '172.18.0.5', 0, '974529453554282547', 0, 0, 0),
(220, 'pahmii', '9048ead9080d9b27d6b2b6ed363cbf8cce795f7f', 0, 0, 'Null', 'None', 'None', '172.18.0.5', 0, '1243028129686229045', 0, 0, 0),
(221, 'dakatek', 'de6de33355fb32b1894dc798314075605ffd377b', 0, 0, 'Null', 'None', 'None', '172.18.0.5', 0, '900707973700157503', 0, 0, 0),
(222, 'bullran', '3040b695e7d9fd2ee01399b8357138183c04bc25', 0, 0, 'Null', 'None', 'None', '180.242.70.193', 0, '744442483865550890', 0, 0, 0),
(223, 'sntcrxz', 'aaea0771fdc0d1e8b8cc5cc357e10d541a6e99aa', 0, 0, 'Null', 'None', 'None', '110.138.83.38', 0, '1065713748578422915', 0, 0, 0),
(224, 'nobua', 'a8a5becf822203c9e6b9e408ff5009fffd1438a4', 0, 0, 'Null', 'None', 'None', '172.18.0.5', 0, '1256467911154077719', 0, 0, 0),
(225, 'Agann', 'f4fe9231abf39e63c8b43d55f9f050520041f14f', 0, 0, 'Null', 'None', 'None', '172.18.0.5', 0, '1293594766436470784', 0, 0, 0),
(226, 'Borisu', 'b12a2bf34263403ee03bb7a1d8a18a8530fa7b16', 0, 0, 'Null', 'None', 'None', '180.245.13.4', 0, '757144706588344362', 0, 0, 0),
(227, 'fahrizal', 'b79db1d1b51d2c9b1dde4229f93048b48b2acb7e', 0, 0, 'Null', 'None', 'None', '36.79.190.206', 0, '1253717100489474051', 0, 0, 0),
(228, 'Auren', 'b089b9d6a2ef713b0f0386f6a80d2873ae8ff6d3', 0, 0, 'Null', 'None', 'None', '114.122.109.195', 0, '747412969423634462', 0, 0, 0),
(229, 'Cikuya', '3a662718b412bfe0023d84b10e325fe04f5a822b', 0, 0, 'Null', 'None', 'None', '103.115.20.39', 0, '1252726890800877583', 0, 0, 0),
(230, 'adaaam', 'fe743b92f90a6cfd12d7fcf226afbb77eb3585f1', 0, 0, 'Null', 'None', 'None', '125.163.74.241', 0, '1315766161954181173', 0, 0, 0),
(231, 'Pelower', '21aaf54f18f7486cc419c13a1bed410ff78ca40c', 0, 0, 'Null', 'None', 'None', '172.18.0.5', 0, '1134783618770800650', 0, 0, 0),
(232, 'Jejee', '929e2ac560b8357f00f5886862909ea39131b559', 0, 0, 'Null', 'None', 'None', '172.18.0.5', 0, '937971455008837714', 0, 0, 0),
(233, 'Arikk', '0e1500d2c1770e0b21a28be8c074e74688277e3f', 0, 0, 'Null', 'None', 'None', '178.128.16.61', 0, '1097818858653483088', 0, 0, 0),
(234, 'rayquaza', '272c410326b4875f0ce36f6d686acb6ef450e78d', 0, 0, 'Null', 'None', 'None', '172.18.0.4', 0, '907051682234531902', 0, 0, 0);

-- --------------------------------------------------------

--
-- Table structure for table `properties`
--

CREATE TABLE `properties` (
  `PropertyDBID` int(11) NOT NULL,
  `PropertyOwnerDBID` int(11) NOT NULL DEFAULT 0,
  `PropertyType` int(11) NOT NULL,
  `PropertyFaction` int(11) NOT NULL DEFAULT 0,
  `PropertyEntranceX` float NOT NULL DEFAULT 0,
  `PropertyEntranceY` float NOT NULL DEFAULT 0,
  `PropertyEntranceZ` float NOT NULL DEFAULT 0,
  `PropertyEntranceInterior` int(11) NOT NULL DEFAULT 0,
  `PropertyEntranceWorld` int(11) NOT NULL DEFAULT 0,
  `PropertyInteriorX` int(11) NOT NULL DEFAULT 0,
  `PropertyInteriorY` int(11) NOT NULL DEFAULT 0,
  `PropertyInteriorZ` int(11) NOT NULL DEFAULT 0,
  `PropertyInteriorIntID` int(11) NOT NULL DEFAULT 0,
  `PropertyInteriorWorld` int(11) NOT NULL DEFAULT 0,
  `PropertyMarketPrice` int(11) NOT NULL DEFAULT 1000,
  `PropertyLevel` int(11) NOT NULL DEFAULT 1,
  `PropertyLocked` tinyint(1) NOT NULL DEFAULT 0,
  `PropertyCashbox` int(11) NOT NULL DEFAULT 0,
  `PropertyAddress` varchar(128) NOT NULL DEFAULT 'None'
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COLLATE=latin1_swedish_ci;

--
-- Dumping data for table `properties`
--

INSERT INTO `properties` (`PropertyDBID`, `PropertyOwnerDBID`, `PropertyType`, `PropertyFaction`, `PropertyEntranceX`, `PropertyEntranceY`, `PropertyEntranceZ`, `PropertyEntranceInterior`, `PropertyEntranceWorld`, `PropertyInteriorX`, `PropertyInteriorY`, `PropertyInteriorZ`, `PropertyInteriorIntID`, `PropertyInteriorWorld`, `PropertyMarketPrice`, `PropertyLevel`, `PropertyLocked`, `PropertyCashbox`, `PropertyAddress`) VALUES
(43, 1, 3, 0, 2495.41, -1691.14, 14.7656, 0, 0, 330, 462, 998, 8, 12217, 8000000, 0, 0, 0, '1th Grove Street'),
(44, 0, 1, 0, 2523.27, -1679.35, 15.497, 0, 0, 239, 462, 998, 5, 34706, 5000000, 0, 0, 0, '2th Grove Street'),
(45, 0, 1, 0, 2524.71, -1658.47, 15.824, 0, 0, 239, 462, 998, 5, 8850, 5000000, 0, 0, 0, '3th Grove Street'),
(46, 0, 1, 0, 2513.69, -1650.22, 14.3557, 0, 0, 239, 462, 998, 5, 14672, 5000000, 0, 0, 0, '4th Grove Street'),
(47, 0, 1, 0, 2498.49, -1642.25, 14.1131, 0, 0, 239, 462, 998, 5, 36876, 5000000, 0, 0, 0, '5th Grove Street'),
(48, 0, 1, 0, 2486.44, -1644.53, 14.0772, 0, 0, 239, 462, 998, 5, 34955, 5000000, 0, 0, 0, '6th Grove Street'),
(49, 0, 1, 0, 2469.42, -1646.35, 13.7801, 0, 0, 239, 462, 998, 5, 22099, 5000000, 0, 0, 0, '7th Grove Street'),
(50, 0, 1, 0, 2451.89, -1641.41, 14.0662, 0, 0, 239, 462, 998, 5, 24778, 5000000, 0, 0, 0, '8th Grove Street'),
(51, 0, 1, 0, 2413.95, -1646.79, 14.0119, 0, 0, 239, 462, 998, 5, 15852, 5000000, 0, 0, 0, '9th Grove Street'),
(52, 0, 1, 0, 2393.18, -1646.03, 13.9051, 0, 0, 239, 462, 998, 5, 27941, 5000000, 0, 0, 0, '10th Grove Street'),
(53, 0, 1, 0, 2362.82, -1643.14, 14.3516, 0, 0, 239, 462, 998, 5, 33138, 5000000, 0, 0, 0, '11th Grove Street'),
(54, 0, 1, 0, 2368.32, -1675.35, 14.1682, 0, 0, 239, 462, 998, 5, 16685, 5000000, 0, 0, 0, '12th Grove Street'),
(55, 0, 1, 0, 2384.66, -1675.84, 15.2457, 0, 0, 239, 462, 998, 5, 36724, 5000000, 0, 0, 0, '13th Grove Street'),
(56, 0, 1, 0, 2408.99, -1674.94, 14.375, 0, 0, 239, 462, 998, 5, 23887, 5000000, 0, 0, 0, '14th Grove Street'),
(57, 0, 1, 0, 2326.88, -1681.9, 14.9297, 0, 0, 239, 462, 998, 5, 9631, 5000000, 0, 0, 0, '15th Grove Street'),
(58, 0, 1, 0, 2326.67, -1716.71, 14.2379, 0, 0, 239, 462, 998, 5, 4635, 5000000, 0, 0, 0, '16th Grove Street'),
(59, 0, 1, 0, 2308.79, -1714.33, 14.9801, 0, 0, 239, 462, 998, 5, 23603, 5000000, 0, 0, 0, '17th Grove Street'),
(60, 0, 1, 0, 2306.9, -1679.2, 14.3316, 0, 0, 239, 462, 998, 5, 25612, 5000000, 0, 0, 0, '18th Grove Street'),
(61, 0, 1, 0, 2282.18, -1641.22, 15.8898, 0, 0, 239, 462, 998, 5, 23174, 5000000, 0, 0, 0, '19th Grove Street'),
(62, 0, 1, 0, 2257.17, -1643.95, 15.8082, 0, 0, 239, 462, 998, 5, 4726, 5000000, 0, 0, 0, '20th Grove Street'),
(63, 0, 1, 0, 2244.46, -1637.61, 16.2379, 0, 0, 239, 462, 998, 5, 31782, 5000000, 0, 0, 0, '21th Grove Street'),
(64, 0, 1, 0, 2385.37, -1711.65, 14.2422, 0, 0, 239, 462, 998, 5, 24396, 5000000, 0, 0, 0, '22th Grove Street'),
(65, 0, 1, 0, 2402.45, -1714.96, 14.1328, 0, 0, 239, 462, 998, 5, 20388, 5000000, 0, 0, 0, '23th Grove Street'),
(66, 0, 1, 0, 2067.05, -1731.74, 14.2066, 0, 0, 239, 462, 998, 5, 26940, 5000000, 0, 0, 0, '24th 106th Street'),
(67, 0, 1, 0, 2066.24, -1717.16, 14.1363, 0, 0, 239, 462, 998, 5, 16491, 5000000, 0, 0, 0, '25th 106th Street'),
(68, 0, 1, 0, 2065.1, -1703.54, 14.1484, 0, 0, 239, 462, 998, 5, 14694, 5000000, 0, 0, 0, '26th 106th Street'),
(69, 0, 1, 0, 2066.74, -1656.5, 14.1328, 0, 0, 239, 462, 998, 5, 14993, 5000000, 0, 0, 0, '27th 106th Street'),
(70, 0, 1, 0, 2067.56, -1643.72, 14.1363, 0, 0, 239, 462, 998, 5, 24055, 5000000, 0, 0, 0, '28th 106th Street'),
(71, 0, 1, 0, 2067.7, -1628.82, 14.2066, 0, 0, 239, 462, 998, 5, 37601, 5000000, 0, 0, 0, '29th 106th Street'),
(72, 0, 1, 0, 2018.06, -1629.8, 14.0426, 0, 0, 239, 462, 998, 5, 25438, 5000000, 0, 0, 0, '30th 107th Street'),
(73, 0, 1, 0, 2016.54, -1641.65, 14.1129, 0, 0, 239, 462, 998, 5, 12987, 5000000, 0, 0, 0, '31th 107th Street'),
(74, 0, 1, 0, 2013.54, -1656.36, 14.1363, 0, 0, 239, 462, 998, 5, 25044, 5000000, 0, 0, 0, '32th 107th Street'),
(75, 0, 1, 0, 2018.24, -1703.27, 14.2344, 0, 0, 239, 462, 998, 5, 5936, 5000000, 0, 0, 0, '33th 107th Street'),
(76, 0, 1, 0, 2016.2, -1716.88, 14.125, 0, 0, 239, 462, 998, 5, 20126, 5000000, 0, 0, 0, '34th 107th Street'),
(77, 0, 1, 0, 2015.35, -1732.62, 14.2344, 0, 0, 239, 462, 998, 5, 33241, 5000000, 0, 0, 0, '35th 107th Street'),
(78, 0, 1, 0, 2437.92, -2020.85, 13.9025, 0, 0, 239, 462, 998, 5, 1661, 5000000, 0, 0, 0, '36th Arbutus Street'),
(79, 0, 1, 0, 2465.38, -2020.79, 14.1242, 0, 0, 239, 462, 998, 5, 30267, 5000000, 0, 0, 0, '37th Arbutus Street'),
(80, 0, 1, 0, 2486.45, -2021.55, 13.9988, 0, 0, 239, 462, 998, 5, 25615, 5000000, 0, 0, 0, '38th Arbutus Street'),
(81, 0, 1, 0, 2507.88, -2021.05, 14.2101, 0, 0, 239, 462, 998, 5, 21490, 5000000, 0, 0, 0, '39th Arbutus Street'),
(82, 0, 1, 0, 2522.78, -2018.97, 14.0744, 0, 0, 239, 462, 998, 5, 12219, 5000000, 0, 0, 0, '40th Arbutus Street'),
(83, 0, 1, 0, 2524.4, -1998.36, 14.1131, 0, 0, 239, 462, 998, 5, 39328, 5000000, 0, 0, 0, '41th Arbutus Street'),
(84, 0, 1, 0, 2508.35, -1998.37, 13.9025, 0, 0, 239, 462, 998, 5, 15032, 5000000, 0, 0, 0, '42th Arbutus Street'),
(85, 0, 1, 0, 2483.34, -1995.34, 13.8343, 0, 0, 239, 462, 998, 5, 27278, 5000000, 0, 0, 0, '43th Arbutus Street'),
(86, 0, 1, 0, 0, 0, 0, 0, 0, 239, 462, 998, 5, 16240, 5000000, 0, 0, 0, ''),
(87, 0, 1, 0, 2465.08, -1995.75, 14.0193, 0, 0, 239, 462, 998, 5, 9108, 5000000, 0, 0, 0, '45th Arbutus Street'),
(88, 78, 1, 0, 2459.53, -1691.5, 13.5446, 0, 0, 239, 462, 998, 5, 5585, 5000000, 0, 0, 0, '46th Grove Street');

-- --------------------------------------------------------

--
-- Table structure for table `propertiesstorage`
--

CREATE TABLE `propertiesstorage` (
  `ID` int(11) NOT NULL DEFAULT 0,
  `itemID` int(11) NOT NULL,
  `itemModel` int(11) NOT NULL DEFAULT 0,
  `itemName` varchar(128) NOT NULL DEFAULT 'none',
  `itemQuantity` int(11) NOT NULL DEFAULT 0
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `propertiesstorage`
--

INSERT INTO `propertiesstorage` (`ID`, `itemID`, `itemModel`, `itemName`, `itemQuantity`) VALUES
(88, 4, 2040, 'JHP Ammo', 16),
(43, 5, 346, 'Colt 45', 1),
(43, 6, 19566, 'Fish Bait', 17),
(88, 7, 348, 'Desert Eagle', 1),
(88, 8, 2040, 'Regular Ammo', 28);

-- --------------------------------------------------------

--
-- Table structure for table `relations`
--

CREATE TABLE `relations` (
  `ID` int(11) NOT NULL,
  `RelationsID` int(11) NOT NULL DEFAULT 0,
  `BusinessID` int(11) NOT NULL DEFAULT 0,
  `RelationsPoints` int(11) NOT NULL DEFAULT 0,
  `RelationsBusinessName` varchar(90) NOT NULL DEFAULT 'none'
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `relations`
--

INSERT INTO `relations` (`ID`, `RelationsID`, `BusinessID`, `RelationsPoints`, `RelationsBusinessName`) VALUES
(4, 1, 18, 115, 'Unknown'),
(5, 90, 18, 105, 'Unknown'),
(6, 65, 18, 130, 'Unknown'),
(7, 90, 23, 165, 'Well Pizza Stack'),
(8, 90, 17, 165, 'Ganton Clothes Conwell.co'),
(9, 138, 17, 100, 'Ganton Clothes Conwell.co'),
(10, 143, 18, 110, 'Unknown'),
(11, 80, 23, 125, 'Well Pizza Stack'),
(12, 71, 21, 110, 'Ganton Bar'),
(13, 146, 18, 115, 'Unknown'),
(14, 1, 17, 100, 'Ganton Clothes Conwell.co'),
(15, 143, 23, 100, 'Well Pizza Stack'),
(16, 148, 18, 115, 'Unknown'),
(17, 80, 18, 105, 'Unknown');

-- --------------------------------------------------------

--
-- Table structure for table `server_data`
--

CREATE TABLE `server_data` (
  `id` int(12) NOT NULL,
  `fish` int(11) NOT NULL DEFAULT 0,
  `fabric` int(11) NOT NULL DEFAULT 0,
  `steel` int(11) NOT NULL DEFAULT 0,
  `woods` int(11) NOT NULL DEFAULT 0,
  `foods` int(11) NOT NULL DEFAULT 0,
  `clothes` int(11) NOT NULL DEFAULT 0,
  `appliances` int(11) NOT NULL DEFAULT 0,
  `materials` int(11) NOT NULL DEFAULT 0,
  `drugs` int(11) NOT NULL DEFAULT 0
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `server_data`
--

INSERT INTO `server_data` (`id`, `fish`, `fabric`, `steel`, `woods`, `foods`, `clothes`, `appliances`, `materials`, `drugs`) VALUES
(0, 0, 100, 100, 100, 100, 100, 100, 7, 100);

-- --------------------------------------------------------

--
-- Table structure for table `spawnables`
--

CREATE TABLE `spawnables` (
  `spawnablesID` int(11) NOT NULL,
  `spawnablesX` float NOT NULL DEFAULT 0,
  `spawnablesY` float NOT NULL DEFAULT 0,
  `spawnablesZ` float NOT NULL DEFAULT 0,
  `spawnablesRX` float NOT NULL DEFAULT 0,
  `spawnablesRY` float NOT NULL DEFAULT 0,
  `spawnablesRZ` float NOT NULL DEFAULT 0,
  `spawnablesInterior` int(11) NOT NULL DEFAULT 0,
  `spawnablesWorld` int(11) NOT NULL DEFAULT 0,
  `spawnablesObjectID` int(11) NOT NULL DEFAULT 0,
  `spawnablesType` int(11) NOT NULL DEFAULT 0,
  `spawnablesAmount` int(11) NOT NULL DEFAULT 0,
  `spawnablesOwner` int(11) NOT NULL DEFAULT 0
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

-- --------------------------------------------------------

--
-- Table structure for table `spray_tags`
--

CREATE TABLE `spray_tags` (
  `id` int(11) UNSIGNED NOT NULL,
  `owner` int(11) NOT NULL DEFAULT 0,
  `vehicle` int(11) NOT NULL DEFAULT -1,
  `text` varchar(128) NOT NULL DEFAULT 'Exemplo',
  `models` int(11) NOT NULL DEFAULT 0,
  `type` int(11) NOT NULL DEFAULT 0,
  `font` varchar(128) NOT NULL DEFAULT 'Arial',
  `fontsize` int(11) NOT NULL DEFAULT 24,
  `bold` int(11) NOT NULL DEFAULT 0,
  `color` int(11) NOT NULL DEFAULT 0,
  `posx` varchar(32) DEFAULT '0.0',
  `posy` varchar(32) DEFAULT '0.0',
  `posz` varchar(32) DEFAULT '0.0',
  `posrx` varchar(32) DEFAULT '0.0',
  `posry` varchar(32) DEFAULT '0.0',
  `posrz` varchar(32) DEFAULT NULL,
  `vw` int(11) DEFAULT 0,
  `interior` int(11) DEFAULT 0
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COLLATE=latin1_swedish_ci;

-- --------------------------------------------------------

--
-- Table structure for table `tickets`
--

CREATE TABLE `tickets` (
  `ID` int(11) NOT NULL DEFAULT 0,
  `DBID` int(11) NOT NULL DEFAULT 0,
  `Fee` int(11) NOT NULL DEFAULT 0,
  `Reason` varchar(64) NOT NULL DEFAULT 'None',
  `Date` varchar(36) NOT NULL DEFAULT 'None'
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `tickets`
--

INSERT INTO `tickets` (`ID`, `DBID`, `Fee`, `Reason`, `Date`) VALUES
(1, 0, 100, 'maling', 'December 29, 2024 14:15:08'),
(65, 0, 100, 'tester', 'December 29, 2024 10:04:21'),
(78, 0, 100, 'tester', 'December 26, 2024 18:59:26');

-- --------------------------------------------------------

--
-- Table structure for table `toys`
--

CREATE TABLE `toys` (
  `Id` int(10) NOT NULL,
  `Owner` int(11) NOT NULL DEFAULT 0,
  `Slot0_Model` int(8) NOT NULL DEFAULT 0,
  `Slot0_Bone` int(8) NOT NULL DEFAULT 0,
  `Slot0_XPos` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot0_YPos` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot0_ZPos` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot0_XRot` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot0_YRot` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot0_ZRot` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot0_XScale` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot0_YScale` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot0_ZScale` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot1_Model` int(8) NOT NULL DEFAULT 0,
  `Slot1_Bone` int(8) NOT NULL DEFAULT 0,
  `Slot1_XPos` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot1_YPos` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot1_ZPos` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot1_XRot` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot1_YRot` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot1_ZRot` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot1_XScale` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot1_YScale` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot1_ZScale` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot2_Model` int(8) NOT NULL DEFAULT 0,
  `Slot2_Bone` int(8) NOT NULL DEFAULT 0,
  `Slot2_XPos` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot2_YPos` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot2_ZPos` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot2_XRot` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot2_YRot` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot2_ZRot` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot2_XScale` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot2_YScale` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot2_ZScale` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot3_Model` int(8) NOT NULL DEFAULT 0,
  `Slot3_Bone` int(8) NOT NULL DEFAULT 0,
  `Slot3_XPos` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot3_YPos` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot3_ZPos` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot3_XRot` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot3_YRot` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot3_ZRot` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot3_XScale` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot3_YScale` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot3_ZScale` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot4_Model` int(8) NOT NULL DEFAULT 0,
  `Slot4_Bone` int(8) NOT NULL DEFAULT 0,
  `Slot4_XPos` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot4_YPos` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot4_ZPos` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot4_XRot` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot4_YRot` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot4_ZRot` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot4_XScale` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot4_YScale` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot4_ZScale` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot5_Model` int(8) NOT NULL DEFAULT 0,
  `Slot5_Bone` int(8) NOT NULL DEFAULT 0,
  `Slot5_XPos` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot5_YPos` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot5_ZPos` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot5_XRot` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot5_YRot` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot5_ZRot` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot5_XScale` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot5_YScale` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot5_ZScale` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot0_Toggle` int(3) NOT NULL DEFAULT 0,
  `Slot1_Toggle` int(3) NOT NULL DEFAULT 0,
  `Slot2_Toggle` int(3) NOT NULL DEFAULT 0,
  `Slot3_Toggle` int(3) NOT NULL DEFAULT 0,
  `Slot4_Toggle` int(3) NOT NULL DEFAULT 0,
  `Slot0_Type` int(11) NOT NULL DEFAULT 0,
  `Slot1_Type` int(11) NOT NULL DEFAULT 0,
  `Slot2_Type` int(11) NOT NULL DEFAULT 0,
  `Slot3_Type` int(11) NOT NULL DEFAULT 0
) ENGINE=MyISAM DEFAULT CHARSET=latin1 COLLATE=latin1_swedish_ci;

--
-- Dumping data for table `toys`
--

INSERT INTO `toys` (`Id`, `Owner`, `Slot0_Model`, `Slot0_Bone`, `Slot0_XPos`, `Slot0_YPos`, `Slot0_ZPos`, `Slot0_XRot`, `Slot0_YRot`, `Slot0_ZRot`, `Slot0_XScale`, `Slot0_YScale`, `Slot0_ZScale`, `Slot1_Model`, `Slot1_Bone`, `Slot1_XPos`, `Slot1_YPos`, `Slot1_ZPos`, `Slot1_XRot`, `Slot1_YRot`, `Slot1_ZRot`, `Slot1_XScale`, `Slot1_YScale`, `Slot1_ZScale`, `Slot2_Model`, `Slot2_Bone`, `Slot2_XPos`, `Slot2_YPos`, `Slot2_ZPos`, `Slot2_XRot`, `Slot2_YRot`, `Slot2_ZRot`, `Slot2_XScale`, `Slot2_YScale`, `Slot2_ZScale`, `Slot3_Model`, `Slot3_Bone`, `Slot3_XPos`, `Slot3_YPos`, `Slot3_ZPos`, `Slot3_XRot`, `Slot3_YRot`, `Slot3_ZRot`, `Slot3_XScale`, `Slot3_YScale`, `Slot3_ZScale`, `Slot4_Model`, `Slot4_Bone`, `Slot4_XPos`, `Slot4_YPos`, `Slot4_ZPos`, `Slot4_XRot`, `Slot4_YRot`, `Slot4_ZRot`, `Slot4_XScale`, `Slot4_YScale`, `Slot4_ZScale`, `Slot5_Model`, `Slot5_Bone`, `Slot5_XPos`, `Slot5_YPos`, `Slot5_ZPos`, `Slot5_XRot`, `Slot5_YRot`, `Slot5_ZRot`, `Slot5_XScale`, `Slot5_YScale`, `Slot5_ZScale`, `Slot0_Toggle`, `Slot1_Toggle`, `Slot2_Toggle`, `Slot3_Toggle`, `Slot4_Toggle`, `Slot0_Type`, `Slot1_Type`, `Slot2_Type`, `Slot3_Type`) VALUES
(18, 11, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(17, 9, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(16, 10, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(15, 1, 0, 2, 0.121, 0.000, 0.011, 0.000, 0.000, 0.000, 1.555, 0.948, 1.000, 0, 2, 0.114, 0.069, -0.004, -62.600, 89.500, 150.000, 0.842, 1.023, 1.263, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(19, 12, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(20, 13, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(21, 14, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(22, 15, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(23, 16, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(24, 17, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(25, 18, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(26, 19, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(27, 20, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(28, 21, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(29, 22, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(30, 23, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(31, 24, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(32, 26, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(33, 28, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(34, 31, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(35, 32, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(36, 33, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(37, 29, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(38, 34, 18640, 2, 0.067, 0.000, 0.000, 0.000, 0.000, 0.000, 1.000, 1.000, 1.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(39, 35, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(40, 36, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(41, 37, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(42, 38, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(43, 39, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(44, 40, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(45, 43, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(46, 44, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(47, 45, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(48, 46, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(49, 49, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(50, 50, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(51, 51, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(52, 52, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(53, 53, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(54, 56, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(55, 57, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(56, 58, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(57, 59, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(58, 60, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(59, 61, 18968, 2, 0.104, -0.013, 0.003, -96.800, 116.100, 0.000, 0.934, 1.044, 0.911, 19033, 2, 0.091, 0.050, 0.000, 46.000, 85.800, 44.000, 0.834, 1.015, 1.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(60, 62, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(61, 63, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(62, 64, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(63, 65, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(64, 66, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(65, 67, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(66, 69, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(67, 70, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(68, 71, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(69, 73, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(70, 74, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(71, 76, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(72, 77, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(73, 78, 18961, 2, 0.118, 0.016, -0.017, 0.000, 100.100, 89.600, 1.353, 1.145, 0.954, 0, 2, 0.125, 0.000, 0.000, 11.500, -5.400, -6.100, 1.000, 1.000, 1.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(74, 79, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(75, 80, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(76, 81, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(77, 82, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(78, 84, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(79, 85, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(80, 86, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(81, 87, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(82, 89, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(83, 90, 0, 1, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(84, 91, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(85, 92, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(86, 93, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(87, 94, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(88, 95, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(89, 97, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(90, 98, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(91, 99, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(92, 100, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(93, 101, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(94, 102, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(95, 103, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(96, 104, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(97, 105, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(98, 106, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(99, 107, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(100, 108, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(101, 109, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(102, 110, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(103, 111, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(104, 112, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(105, 113, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(106, 114, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(107, 117, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(108, 118, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(109, 119, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(110, 121, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(111, 122, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(112, 123, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(113, 124, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(114, 125, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(115, 126, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(116, 127, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(117, 128, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(118, 129, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(119, 130, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(120, 131, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(121, 132, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(122, 133, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0, 0, 0, 0, 0, 0, 0);
INSERT INTO `toys` (`Id`, `Owner`, `Slot0_Model`, `Slot0_Bone`, `Slot0_XPos`, `Slot0_YPos`, `Slot0_ZPos`, `Slot0_XRot`, `Slot0_YRot`, `Slot0_ZRot`, `Slot0_XScale`, `Slot0_YScale`, `Slot0_ZScale`, `Slot1_Model`, `Slot1_Bone`, `Slot1_XPos`, `Slot1_YPos`, `Slot1_ZPos`, `Slot1_XRot`, `Slot1_YRot`, `Slot1_ZRot`, `Slot1_XScale`, `Slot1_YScale`, `Slot1_ZScale`, `Slot2_Model`, `Slot2_Bone`, `Slot2_XPos`, `Slot2_YPos`, `Slot2_ZPos`, `Slot2_XRot`, `Slot2_YRot`, `Slot2_ZRot`, `Slot2_XScale`, `Slot2_YScale`, `Slot2_ZScale`, `Slot3_Model`, `Slot3_Bone`, `Slot3_XPos`, `Slot3_YPos`, `Slot3_ZPos`, `Slot3_XRot`, `Slot3_YRot`, `Slot3_ZRot`, `Slot3_XScale`, `Slot3_YScale`, `Slot3_ZScale`, `Slot4_Model`, `Slot4_Bone`, `Slot4_XPos`, `Slot4_YPos`, `Slot4_ZPos`, `Slot4_XRot`, `Slot4_YRot`, `Slot4_ZRot`, `Slot4_XScale`, `Slot4_YScale`, `Slot4_ZScale`, `Slot5_Model`, `Slot5_Bone`, `Slot5_XPos`, `Slot5_YPos`, `Slot5_ZPos`, `Slot5_XRot`, `Slot5_YRot`, `Slot5_ZRot`, `Slot5_XScale`, `Slot5_YScale`, `Slot5_ZScale`, `Slot0_Toggle`, `Slot1_Toggle`, `Slot2_Toggle`, `Slot3_Toggle`, `Slot4_Toggle`, `Slot0_Type`, `Slot1_Type`, `Slot2_Type`, `Slot3_Type`) VALUES
(123, 134, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(124, 135, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(125, 136, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(126, 137, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(127, 138, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(128, 139, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(129, 140, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(130, 142, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(131, 143, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(132, 144, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(133, 145, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(134, 146, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(135, 147, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(136, 148, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(137, 149, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(138, 151, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0, 0, 0, 0, 0, 0, 0);

-- --------------------------------------------------------

--
-- Table structure for table `trashcan`
--

CREATE TABLE `trashcan` (
  `DBID` int(11) NOT NULL,
  `capacity` int(11) NOT NULL DEFAULT 0,
  `posx` float NOT NULL,
  `posy` float NOT NULL,
  `posz` float NOT NULL,
  `posa` float NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

-- --------------------------------------------------------

--
-- Table structure for table `tree`
--

CREATE TABLE `tree` (
  `id` int(11) NOT NULL,
  `posx` float NOT NULL DEFAULT 0,
  `posy` float NOT NULL DEFAULT 0,
  `posz` float NOT NULL DEFAULT 0,
  `posrx` float NOT NULL DEFAULT 0,
  `posry` float NOT NULL DEFAULT 0,
  `posrz` float NOT NULL DEFAULT 0,
  `time` int(11) NOT NULL DEFAULT 0
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `tree`
--

INSERT INTO `tree` (`id`, `posx`, `posy`, `posz`, `posrx`, `posry`, `posrz`, `time`) VALUES
(1, -1275.46, -1463.03, 103.33, 0, 0, 336.66, 0),
(2, -655.291, -1217.52, 23.9903, 0, 0, 20.517, 0),
(3, -607.704, -1426.91, 13.9335, 0, 0, 185.812, 0),
(4, -594.379, -1560.64, 11.3064, 0, 0, 282.577, 0),
(5, -554.959, -1578.05, 7.12028, 0, 0, 282.503, 0),
(6, -554.475, -1529.97, 8.11248, 0, 0, 24.4885, 0),
(7, -600.535, -884.585, 105.698, 0, 0, 311.916, 0),
(8, -1267.13, -1464.79, 103.757, 0, 0, 266.549, 0),
(9, -1260.45, -1465.9, 103.997, 0, 0, 273.535, 0),
(10, -1268.36, -1448.3, 104.568, 0, 0, 1.32987, 0),
(11, -1272.18, -1439.5, 104.914, 0, 0, 85.0793, 0),
(12, -1069.55, -1727.9, 75.4672, 0, 0, 355.816, 0),
(13, -1091.72, -1715.5, 75.4172, 0, 0, 77.4329, 0),
(14, -993.998, -1326.76, 136.929, 0, 0, 157.656, 0),
(15, -1088.33, -1318.77, 128.31, 0, 0, 83.8325, 0),
(16, -460.239, -691.521, 18.9669, 5.9, 0, 157.215, 0),
(17, -808.493, -423.643, 13.995, 0, 0, 150.008, 0);

-- --------------------------------------------------------

--
-- Table structure for table `vehicles`
--

CREATE TABLE `vehicles` (
  `VehicleDBID` int(11) NOT NULL,
  `VehicleOwnerDBID` int(11) NOT NULL,
  `VehicleFaction` int(11) NOT NULL DEFAULT 0,
  `VehicleModel` int(11) NOT NULL DEFAULT 0,
  `VehicleColor1` int(11) NOT NULL DEFAULT 0,
  `VehicleColor2` int(11) NOT NULL DEFAULT 0,
  `VehiclePaintjob` int(11) NOT NULL DEFAULT -1,
  `VehicleParkPosX` float NOT NULL DEFAULT 0,
  `VehicleParkPosY` float NOT NULL DEFAULT 0,
  `VehicleParkPosZ` float NOT NULL DEFAULT 0,
  `VehicleParkPosA` float NOT NULL DEFAULT 0,
  `VehicleParkInterior` int(11) NOT NULL DEFAULT 0,
  `VehicleParkWorld` int(11) NOT NULL DEFAULT 0,
  `VehiclePlates` varchar(32) NOT NULL DEFAULT 'None',
  `VehicleFakePlates` varchar(32) NOT NULL DEFAULT 'None',
  `VehiclePlatesStatus` tinyint(1) NOT NULL DEFAULT 0,
  `VehiclePlatesFake` tinyint(1) NOT NULL DEFAULT 0,
  `VehicleLocked` int(11) NOT NULL DEFAULT 0,
  `VehicleRental` tinyint(1) NOT NULL DEFAULT 0,
  `VehicleRentalTimer` int(11) NOT NULL DEFAULT 0,
  `VehicleImpounded` tinyint(1) NOT NULL DEFAULT 0,
  `VehicleImpoundPosX` float NOT NULL DEFAULT 0,
  `VehicleImpoundPosY` float NOT NULL DEFAULT 0,
  `VehicleImpoundPosZ` float NOT NULL DEFAULT 0,
  `VehicleImpoundPosA` float NOT NULL DEFAULT 0,
  `VehicleSirens` int(11) NOT NULL DEFAULT 0,
  `VehicleFuel` float NOT NULL DEFAULT 100,
  `VehicleMiles` int(11) NOT NULL DEFAULT 0,
  `VehicleLastDrivers1` int(11) NOT NULL DEFAULT 0,
  `VehicleLastDrivers2` int(11) NOT NULL DEFAULT 0,
  `VehicleLastDrivers3` int(11) NOT NULL DEFAULT 0,
  `VehicleLastDrivers4` int(11) NOT NULL DEFAULT 0,
  `VehicleLastPassengers1` int(11) NOT NULL DEFAULT 0,
  `VehicleLastPassengers2` int(11) NOT NULL DEFAULT 0,
  `VehicleLastPassengers3` int(11) NOT NULL DEFAULT 0,
  `VehicleLastPassengers4` int(11) NOT NULL DEFAULT 0,
  `VehicleBattery` float NOT NULL DEFAULT 100,
  `VehicleEngine` float NOT NULL DEFAULT 100,
  `VehicleTimesDestroyed` int(11) NOT NULL DEFAULT 0,
  `VehicleXMR` tinyint(1) NOT NULL DEFAULT 0,
  `VehicleAlarmLevel` int(11) NOT NULL DEFAULT 0,
  `VehicleLockLevel` int(11) NOT NULL DEFAULT 0,
  `VehicleImmobLevel` int(11) NOT NULL DEFAULT 1,
  `VehicleHealth` float NOT NULL DEFAULT 1000,
  `VehicleBody` int(11) NOT NULL DEFAULT 0,
  `VehicleTire` int(11) NOT NULL DEFAULT 0,
  `VehicleMods0` int(11) NOT NULL DEFAULT 0,
  `VehicleMods1` int(11) NOT NULL DEFAULT 0,
  `VehicleMods2` int(11) NOT NULL DEFAULT 0,
  `VehicleMods3` int(11) NOT NULL DEFAULT 0,
  `VehicleMods4` int(11) NOT NULL DEFAULT 0,
  `VehicleMods5` int(11) NOT NULL DEFAULT 0,
  `VehicleMods6` int(11) NOT NULL DEFAULT 0,
  `VehicleMods7` int(11) NOT NULL DEFAULT 0,
  `VehicleMods8` int(11) NOT NULL DEFAULT 0,
  `VehicleMods9` int(11) NOT NULL DEFAULT 0,
  `VehicleMods10` int(11) NOT NULL DEFAULT 0,
  `VehicleMods11` int(11) NOT NULL DEFAULT 0,
  `VehicleMods12` int(11) NOT NULL DEFAULT 0,
  `VehicleMods13` int(11) NOT NULL DEFAULT 0,
  `VehicleMods14` int(11) NOT NULL DEFAULT 0,
  `VehicleMods15` int(11) NOT NULL DEFAULT 0
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COLLATE=latin1_swedish_ci;

--
-- Dumping data for table `vehicles`
--

INSERT INTO `vehicles` (`VehicleDBID`, `VehicleOwnerDBID`, `VehicleFaction`, `VehicleModel`, `VehicleColor1`, `VehicleColor2`, `VehiclePaintjob`, `VehicleParkPosX`, `VehicleParkPosY`, `VehicleParkPosZ`, `VehicleParkPosA`, `VehicleParkInterior`, `VehicleParkWorld`, `VehiclePlates`, `VehicleFakePlates`, `VehiclePlatesStatus`, `VehiclePlatesFake`, `VehicleLocked`, `VehicleRental`, `VehicleRentalTimer`, `VehicleImpounded`, `VehicleImpoundPosX`, `VehicleImpoundPosY`, `VehicleImpoundPosZ`, `VehicleImpoundPosA`, `VehicleSirens`, `VehicleFuel`, `VehicleMiles`, `VehicleLastDrivers1`, `VehicleLastDrivers2`, `VehicleLastDrivers3`, `VehicleLastDrivers4`, `VehicleLastPassengers1`, `VehicleLastPassengers2`, `VehicleLastPassengers3`, `VehicleLastPassengers4`, `VehicleBattery`, `VehicleEngine`, `VehicleTimesDestroyed`, `VehicleXMR`, `VehicleAlarmLevel`, `VehicleLockLevel`, `VehicleImmobLevel`, `VehicleHealth`, `VehicleBody`, `VehicleTire`, `VehicleMods0`, `VehicleMods1`, `VehicleMods2`, `VehicleMods3`, `VehicleMods4`, `VehicleMods5`, `VehicleMods6`, `VehicleMods7`, `VehicleMods8`, `VehicleMods9`, `VehicleMods10`, `VehicleMods11`, `VehicleMods12`, `VehicleMods13`, `VehicleMods14`, `VehicleMods15`) VALUES
(88, 52, 0, 462, 0, 0, -1, 1659.28, -1731.72, 12.9811, 268.901, 0, 0, '7HJG46', 'None', 0, 0, 0, 1, 53, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 100, 100, 0, 0, 0, 0, 1, 1000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(96, 1, 0, 468, 3, 0, -1, 1559.82, -1715.1, 13.2045, 67.9886, 0, 0, '4XYG65', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 437, 0, 0, 0, 0, 0, 0, 0, 0, 100, 100, 0, 0, 0, 0, 1, 1000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(97, 61, 0, 468, 0, 0, -1, 1824.24, -1615.05, 13.0519, 170.887, 0, 0, '1YAQ36', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 383, 0, 0, 0, 0, 0, 0, 0, 0, 100, 100, 0, 0, 0, 0, 1, 1000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(101, 1, 0, 499, 0, 0, -1, 1536, -1667.87, 13.2991, 0.032943, 0, 0, '6LWW14', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 49.5, 1090, 0, 0, 0, 0, 0, 0, 0, 0, 100, 100, 0, 0, 0, 0, 1, 1000, 2097153, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(102, 78, 0, 463, 90, 0, -1, 2683.53, -2516.9, 12.7146, 265.03, 0, 0, '7TLC18', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 54, 92, 0, 0, 0, 0, 0, 0, 0, 0, 100, 100, 0, 0, 0, 0, 1, 1000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1083, 0, 0, 0, 0, 0, 0, 0, 0),
(103, 78, 0, 580, 0, 0, -1, 2474.25, -1707.83, 13.3052, 181.863, 0, 0, 'None', 'None', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 100.5, 1153, 0, 0, 0, 0, 0, 0, 0, 0, 100, 100, 0, 0, 0, 0, 1, 1000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(104, 61, 0, 445, 0, 0, -1, 2278.58, -1679.88, 14.4459, 173.786, 0, 0, 'None', 'None', 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 21, 258, 0, 0, 0, 0, 0, 0, 0, 0, 100, 100, 0, 0, 0, 0, 1, 1000, 1048576, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(105, 90, 0, 401, 0, 0, -1, 2608.85, -1735.41, 11.9511, 269.911, 0, 0, 'None', 'None', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 90, 1691, 0, 0, 0, 0, 0, 0, 0, 0, 100, 100, 0, 0, 0, 0, 1, 1000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(106, 78, 0, 499, 0, 0, -1, 2475.31, -1696.34, 13.5629, 181.602, 0, 0, 'None', 'None', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 0, 0, 0, 100, 100, 0, 0, 0, 0, 1, 1000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(107, 90, 0, 499, 0, 0, -1, 345.149, 887.769, 20.3969, 132.644, 0, 0, 'None', 'None', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 96.5, 7, 0, 0, 0, 0, 0, 0, 0, 0, 100, 100, 0, 0, 0, 0, 1, 1000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(108, 134, 0, 462, 0, 0, -1, 1672.14, -2313.52, -2.65855, 82.3233, 0, 0, 'None', 'None', 0, 0, 0, 1, 60, 0, 0, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 0, 0, 0, 100, 100, 0, 0, 0, 0, 1, 1000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(109, 1, 0, 515, 0, 0, -1, 2460.4, -2529.84, 14.65, 179.635, 0, 0, 'None', 'None', 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 0, 0, 0, 100, 100, 0, 0, 0, 0, 1, 1000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(110, 125, 0, 509, 0, 0, -1, 691.112, -1569.99, 13.7472, 175.469, 0, 0, 'None', 'None', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 0, 0, 0, 100, 100, 0, 0, 0, 0, 1, 1000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(111, 80, 0, 499, 0, 0, -1, 887.417, -1223.25, 16.9659, 130.185, 0, 0, 'None', 'None', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 96.5, 7, 0, 0, 0, 0, 0, 0, 0, 0, 100, 100, 0, 0, 0, 0, 1, 1000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(112, 143, 0, 468, 1, 1, -1, 2099.25, -1804.6, 13.222, 97.3922, 0, 0, 'None', 'None', 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 0, 0, 0, 100, 100, 0, 0, 0, 0, 1, 1000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(113, 142, 0, 405, 0, 0, -1, 1541.03, -1687.49, 13.7061, 256.132, 0, 0, 'None', 'None', 0, 0, 0, 1, 39, 0, 0, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 0, 0, 0, 100, 100, 0, 0, 0, 0, 1, 1000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(114, 142, 0, 462, 0, 0, -1, 1540.47, -1686.89, 13.1489, 259.513, 0, 0, 'None', 'None', 0, 0, 0, 1, 39, 0, 0, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 0, 0, 0, 100, 100, 0, 0, 0, 0, 1, 1000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(115, 1, 0, 405, 0, 0, -1, 1541.19, -1686.21, 13.5521, 138.474, 0, 0, 'None', 'None', 0, 0, 0, 1, 60, 0, 0, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 0, 0, 0, 100, 100, 0, 0, 0, 0, 1, 1000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(117, 124, 0, 462, 0, 0, -1, 1540.72, -1686.8, 13.5494, 340.073, 0, 0, 'None', 'None', 0, 0, 0, 1, 60, 0, 0, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 0, 0, 0, 100, 100, 0, 0, 0, 0, 1, 1000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(118, 65, 0, 515, 0, 0, -1, 808.441, -604.217, 17.3473, 271.292, 0, 0, 'None', 'None', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 97, 6, 0, 0, 0, 0, 0, 0, 0, 0, 100, 100, 0, 0, 0, 0, 1, 1000, 1048592, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);

-- --------------------------------------------------------

--
-- Table structure for table `vstorage`
--

CREATE TABLE `vstorage` (
  `ID` int(11) NOT NULL DEFAULT 0,
  `itemID` int(11) NOT NULL,
  `itemModel` int(11) NOT NULL DEFAULT 0,
  `itemQuantity` int(11) NOT NULL DEFAULT 0,
  `itemName` varchar(32) CHARACTER SET latin1 COLLATE latin1_swedish_ci DEFAULT NULL,
  `type` int(11) NOT NULL DEFAULT 0
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `vstorage`
--

INSERT INTO `vstorage` (`ID`, `itemID`, `itemModel`, `itemQuantity`, `itemName`, `type`) VALUES
(100, 77, 18634, 1, 'Marcos Knife', 0),
(100, 78, -2201, 1, 'Cutscene Bat', 0),
(100, 79, -2202, 1, 'Baseball Bat', 0),
(100, 80, 19570, 1, 'Mint', 0),
(102, 81, 341, 1, 'Chainsaw', 0),
(104, 84, 3014, 4721, 'Materials', 0),
(104, 85, 2040, 30, 'Regular Ammo', 0),
(104, 86, 2040, 35, 'Surplus Ammo', 0),
(104, 87, 352, 1, 'Uzi', 0),
(104, 88, 349, 1, 'Shotgun', 0),
(106, 92, 348, 1, 'Desert Eagle', 0),
(106, 93, 2040, 44, 'Surplus Ammo', 0),
(103, 97, 348, 1, 'Shotgun', 0),
(103, 98, 2040, 50, 'Regular Ammo', 0),
(111, 101, 2912, 1, 'Steel Cargo', 0);

--
-- Indexes for dumped tables
--

--
-- Indexes for table `ajail_logs`
--
ALTER TABLE `ajail_logs`
  ADD PRIMARY KEY (`id`);

--
-- Indexes for table `bannedlist`
--
ALTER TABLE `bannedlist`
  ADD PRIMARY KEY (`id`);

--
-- Indexes for table `ban_logs`
--
ALTER TABLE `ban_logs`
  ADD PRIMARY KEY (`id`);

--
-- Indexes for table `businesses`
--
ALTER TABLE `businesses`
  ADD PRIMARY KEY (`BusinessDBID`);

--
-- Indexes for table `characters`
--
ALTER TABLE `characters`
  ADD PRIMARY KEY (`char_dbid`);

--
-- Indexes for table `compensation_claims`
--
ALTER TABLE `compensation_claims`
  ADD PRIMARY KEY (`player_id`,`code`);

--
-- Indexes for table `compensation_codes`
--
ALTER TABLE `compensation_codes`
  ADD PRIMARY KEY (`id`);

--
-- Indexes for table `contacts`
--
ALTER TABLE `contacts`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `court`
--
ALTER TABLE `court`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `criminal_record`
--
ALTER TABLE `criminal_record`
  ADD PRIMARY KEY (`idx`);

--
-- Indexes for table `dropped`
--
ALTER TABLE `dropped`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `entrance`
--
ALTER TABLE `entrance`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `factions`
--
ALTER TABLE `factions`
  ADD PRIMARY KEY (`DBID`);

--
-- Indexes for table `faction_ranks`
--
ALTER TABLE `faction_ranks`
  ADD PRIMARY KEY (`factionid`),
  ADD UNIQUE KEY `factionid` (`factionid`);

--
-- Indexes for table `furniture`
--
ALTER TABLE `furniture`
  ADD PRIMARY KEY (`id`);

--
-- Indexes for table `gates`
--
ALTER TABLE `gates`
  ADD PRIMARY KEY (`dbid`);

--
-- Indexes for table `inventory`
--
ALTER TABLE `inventory`
  ADD PRIMARY KEY (`invID`);

--
-- Indexes for table `kick_logs`
--
ALTER TABLE `kick_logs`
  ADD PRIMARY KEY (`id`);

--
-- Indexes for table `logs`
--
ALTER TABLE `logs`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `masters`
--
ALTER TABLE `masters`
  ADD PRIMARY KEY (`acc_dbid`);

--
-- Indexes for table `properties`
--
ALTER TABLE `properties`
  ADD PRIMARY KEY (`PropertyDBID`);

--
-- Indexes for table `propertiesstorage`
--
ALTER TABLE `propertiesstorage`
  ADD PRIMARY KEY (`itemID`);

--
-- Indexes for table `relations`
--
ALTER TABLE `relations`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `server_data`
--
ALTER TABLE `server_data`
  ADD PRIMARY KEY (`id`);

--
-- Indexes for table `spawnables`
--
ALTER TABLE `spawnables`
  ADD PRIMARY KEY (`spawnablesID`);

--
-- Indexes for table `spray_tags`
--
ALTER TABLE `spray_tags`
  ADD PRIMARY KEY (`id`);

--
-- Indexes for table `tickets`
--
ALTER TABLE `tickets`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `toys`
--
ALTER TABLE `toys`
  ADD PRIMARY KEY (`Id`),
  ADD UNIQUE KEY `id` (`Owner`);

--
-- Indexes for table `trashcan`
--
ALTER TABLE `trashcan`
  ADD PRIMARY KEY (`DBID`);

--
-- Indexes for table `tree`
--
ALTER TABLE `tree`
  ADD PRIMARY KEY (`id`);

--
-- Indexes for table `vehicles`
--
ALTER TABLE `vehicles`
  ADD PRIMARY KEY (`VehicleDBID`);

--
-- Indexes for table `vstorage`
--
ALTER TABLE `vstorage`
  ADD PRIMARY KEY (`itemID`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `ajail_logs`
--
ALTER TABLE `ajail_logs`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=28;

--
-- AUTO_INCREMENT for table `bannedlist`
--
ALTER TABLE `bannedlist`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=2;

--
-- AUTO_INCREMENT for table `ban_logs`
--
ALTER TABLE `ban_logs`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=2;

--
-- AUTO_INCREMENT for table `businesses`
--
ALTER TABLE `businesses`
  MODIFY `BusinessDBID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=29;

--
-- AUTO_INCREMENT for table `characters`
--
ALTER TABLE `characters`
  MODIFY `char_dbid` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=152;

--
-- AUTO_INCREMENT for table `compensation_codes`
--
ALTER TABLE `compensation_codes`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=15;

--
-- AUTO_INCREMENT for table `court`
--
ALTER TABLE `court`
  MODIFY `ID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=9;

--
-- AUTO_INCREMENT for table `criminal_record`
--
ALTER TABLE `criminal_record`
  MODIFY `idx` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=30;

--
-- AUTO_INCREMENT for table `dropped`
--
ALTER TABLE `dropped`
  MODIFY `ID` int(12) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=183;

--
-- AUTO_INCREMENT for table `entrance`
--
ALTER TABLE `entrance`
  MODIFY `ID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=5;

--
-- AUTO_INCREMENT for table `factions`
--
ALTER TABLE `factions`
  MODIFY `DBID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=16;

--
-- AUTO_INCREMENT for table `faction_ranks`
--
ALTER TABLE `faction_ranks`
  MODIFY `factionid` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=16;

--
-- AUTO_INCREMENT for table `furniture`
--
ALTER TABLE `furniture`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=425;

--
-- AUTO_INCREMENT for table `gates`
--
ALTER TABLE `gates`
  MODIFY `dbid` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=22;

--
-- AUTO_INCREMENT for table `inventory`
--
ALTER TABLE `inventory`
  MODIFY `invID` int(12) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=1111;

--
-- AUTO_INCREMENT for table `kick_logs`
--
ALTER TABLE `kick_logs`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=13;

--
-- AUTO_INCREMENT for table `masters`
--
ALTER TABLE `masters`
  MODIFY `acc_dbid` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=235;

--
-- AUTO_INCREMENT for table `properties`
--
ALTER TABLE `properties`
  MODIFY `PropertyDBID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=89;

--
-- AUTO_INCREMENT for table `propertiesstorage`
--
ALTER TABLE `propertiesstorage`
  MODIFY `itemID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=9;

--
-- AUTO_INCREMENT for table `relations`
--
ALTER TABLE `relations`
  MODIFY `ID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=18;

--
-- AUTO_INCREMENT for table `server_data`
--
ALTER TABLE `server_data`
  MODIFY `id` int(12) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=3;

--
-- AUTO_INCREMENT for table `spawnables`
--
ALTER TABLE `spawnables`
  MODIFY `spawnablesID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=8;

--
-- AUTO_INCREMENT for table `spray_tags`
--
ALTER TABLE `spray_tags`
  MODIFY `id` int(11) UNSIGNED NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=269;

--
-- AUTO_INCREMENT for table `toys`
--
ALTER TABLE `toys`
  MODIFY `Id` int(10) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=139;

--
-- AUTO_INCREMENT for table `trashcan`
--
ALTER TABLE `trashcan`
  MODIFY `DBID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=24;

--
-- AUTO_INCREMENT for table `tree`
--
ALTER TABLE `tree`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=18;

--
-- AUTO_INCREMENT for table `vehicles`
--
ALTER TABLE `vehicles`
  MODIFY `VehicleDBID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=119;

--
-- AUTO_INCREMENT for table `vstorage`
--
ALTER TABLE `vstorage`
  MODIFY `itemID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=102;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
